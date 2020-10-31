#include "q.h"
#include <stdlib.h>
#include <stdio.h>

void queueInit(q *queue)
{
    queue->numItems = 0;
    queue->head = NULL;
    queue->tail = NULL;
}

void q_free(q *queue)
{
    qItem *h = queue->head;
    qItem *next = NULL;

    while(h != NULL)
    {
        printf("Freeing\n");
        next = h->next;
        free(h);
        h = next;
    }
}

void q_enqueue(q *queue, int item)
{
    qItem *newItem = (qItem *) malloc(sizeof(qItem));
    newItem->next = NULL;
    newItem->data = item;
    qItem *h = queue->head; 
    queue->numItems += 1;

    if (queue->tail == NULL)
    {
        queue->tail = newItem;
        queue->head = newItem;
    } 
    else {
        queue->tail->next = newItem;
        queue->tail = queue->tail->next;
    }
}

int q_dequeue(q *queue)
{
    qItem *toFree = queue->head;

    if (queue->head == NULL)
    {
        return -111;
    }
    
    queue->numItems -= 1;

    int data = queue->head->data;

    queue->head = queue->head->next;

    if (queue->head == NULL)
    {
        queue->tail = NULL;
    }
    
    free(toFree);

    return data;
}

void q_print(q *queue)
{
    qItem *cur = queue->head;
    printf("queue num items: %d\n", queue->numItems);
    while(cur != NULL)
    {
        printf("item value: %d\n", cur->data);
        cur = cur->next;
    }
}