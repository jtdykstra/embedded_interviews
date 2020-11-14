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
int consumeCount = 10;
int consumeCountOne = 5;

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

void *consumerZero(void *arg)
{
    while(consumeCount--)
    {
        sem_wait(&fillCount);
        pthread_mutex_lock(&lock);
        int item = q_dequeue(&queue);
        pthread_mutex_unlock(&lock);
        sem_post(&emptyCount);
        printf("consumerZero consumed item %d\n", item);
    }
}

void *consumerOne(void *arg)
{
    while(consumeCountOne--)
    {
        sem_wait(&fillCount);
        pthread_mutex_lock(&lock);
        int item = q_dequeue(&queue);
        pthread_mutex_unlock(&lock);
        sem_post(&emptyCount);
        printf("consumerOne consumed item %d\n", item);
    }
}

int main() {
    pthread_t threadOneId;
    pthread_t threadTwoId;
    pthread_t threadThreeId;

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
    int err2 = pthread_create(&threadTwoId, NULL, &consumerZero, NULL);
    int err3 = pthread_create(&threadThreeId, NULL, &consumerOne, NULL);
    
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}
