#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "q.h"

q queue;
sem_t emptyCount;
sem_t fillCount;
pthread_mutex_t lock;
int produceCount = 15;
int consumeCount = 15;

int produceItem()
{
    return rand() % 5;
}

void *producer(void *arg)
{
    while(produceCount--)
    {
        int item = produceItem();
        printf("produced item %d\n", item);
        sem_wait(&emptyCount);
        pthread_mutex_lock(&lock);
        q_enqueue(&queue, item);
        pthread_mutex_unlock(&lock);
        sem_post(&fillCount);
    }
}

void *consumer(void *arg)
{
    while(consumeCount--)
    {
        sem_wait(&fillCount);
        pthread_mutex_lock(&lock);
        int item = q_dequeue(&queue);
        pthread_mutex_unlock(&lock);
        sem_post(&emptyCount);
        printf("consumed item %d\n", item);
    }
}

int main() {
    pthread_t threadOneId;
    pthread_t threadTwoId;

    sem_init(&fillCount, 0, 0);
    sem_init(&emptyCount, 0, 1);

    pthread_mutex_init(&lock, NULL);

    queueInit(&queue);
    /*q_enqueue(&queue, 1);
    q_enqueue(&queue, 2);
    q_enqueue(&queue, 3);
    q_print(&queue);
    printf("dequeue %d\n", q_dequeue(&queue));
    printf("dequeue %d\n", q_dequeue(&queue));
    printf("dequeue %d\n", q_dequeue(&queue));
    q_print(&queue);
    q_free(&queue);*/

    int err1 = pthread_create(&threadOneId, NULL, &producer, NULL);
    int err2 = pthread_create(&threadTwoId, NULL, &consumer, NULL);
    
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}
