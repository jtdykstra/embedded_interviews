#include <stdio.h>
#include <assert.h>
#include <string.h>

#define QUEUE_SIZE 5 

typedef struct queue {
    int data[10];
    int head;
    int tail;
} Queue;

void queue_add(Queue *q, int data)
{
    if ((q->head + 1) % QUEUE_SIZE == (q->tail % QUEUE_SIZE))
    {
        return;
    }

    q->data[(q->head % QUEUE_SIZE)] = data;
    q->head += 1;
}

int queue_remove(Queue *q)
{
    // empty queue
    if ((q->head % QUEUE_SIZE) == (q->tail % QUEUE_SIZE))
    {
        return 0xDEADBEEF;
    }

    int d = q->data[(q->tail % QUEUE_SIZE)];
    ++q->tail;
    return d;
}

int main()
{
    Queue q;
    memset(&q, 0, sizeof(q));

    queue_add(&q, 1);
    queue_add(&q, 2);
    queue_add(&q, 3);
    queue_add(&q, 4);
    queue_add(&q, 5); // expecting this to be dropped
    queue_add(&q, 6); // expecting this to be dropped

    assert(queue_remove(&q) == 1);
    assert(queue_remove(&q) == 2);
    assert(queue_remove(&q) == 3);
    assert(queue_remove(&q) == 4);
    assert(queue_remove(&q) == 0xDEADBEEF);
    assert(queue_remove(&q) == 0xDEADBEEF);

    queue_add(&q, 1);
    queue_add(&q, 2);
    queue_add(&q, 3);
    queue_add(&q, 4);
    queue_add(&q, 5); // expecting this to be dropped
    queue_add(&q, 6); // expecting this to be dropped

    assert(queue_remove(&q) == 1);
    assert(queue_remove(&q) == 2);
    assert(queue_remove(&q) == 3);
    assert(queue_remove(&q) == 4);
    assert(queue_remove(&q) == 0xDEADBEEF);
    assert(queue_remove(&q) == 0xDEADBEEF);
}