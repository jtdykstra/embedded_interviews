#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
   0 1 2 3 4 5
   0 1 10 2
*/
typedef struct heapItem {
    int data;
} HeapItem;

typedef struct heap {
    HeapItem *start;
    int numItems;
    int maxSize;
} Heap;

HeapItem *getItem(Heap *h, int index)
{
    return &h->start[index];
}

void swap(Heap *h, int left, int right)
{
    int temp = getItem(h, left)->data;
    getItem(h, left)->data = getItem(h,right)->data;
    getItem(h, right)->data = temp;
}

void initHeap(Heap *h, int size)
{
    h->start = malloc(sizeof(HeapItem)*size);
    h->numItems = 0;
    h->maxSize = size;
}

// sift up version
void heapPush(Heap *h, int data)
{
    getItem(h, h->numItems)->data = data;
    h->numItems += 1;

    // sift up 
    int current = h->numItems - 1;
    while(current > 0)
    {
        int parent = (current - 1) / 2;
        printf("heapAdd: current is %d, parent is %d\n", current, parent);
        // item is now in the correct place, break out
        if (getItem(h, current)->data >= getItem(h,parent)->data)
        {
            printf("stopping\n");
            break;
        }
        // swap parent and child
        swap(h, current, parent);

        // current is now the parent
        current = parent;

        // continue sifting up
    }

    // item should now be in the right spot
}

// sift down version
int heapPop(Heap *h)
{
    // get data to return
    int toReturn = getItem(h, 0)->data;

    // place last item into top and decrease size
    getItem(h, 0)->data = getItem(h,h->numItems - 1)->data;
    h->numItems -= 1;

    int current = 0;
    while(current < h->numItems)
    {
        // current is greater than the left child
        // proceed in that direction
        if ((current * 2 + 1) <= h->numItems && 
             getItem(h, current)->data > getItem(h, current*2+1)->data)
        {
            swap(h, current, current*2 + 1);
            current = current*2 + 1;
        }
        // current is greater than the right child
        // proceed in that direction
        else if ((current * 2 + 2) <= h->numItems &&
                  getItem(h,current)->data > getItem(h, current*2 + 2)->data)
        {
            swap(h, current, current*2 + 2);
            current = current*2 + 2;
        }
        // current is greater than or equal both children. 
        // It's in the right place!
        else
        {
            break;
        }
    }

    return toReturn;
}

void destructHeap(Heap *h)
{
    free(h->start);
}

void printHeap(Heap *h)
{
    for (int i = 0; i < h->numItems; ++i)
    {
        printf("item at %d is %d, | ", i, getItem(h, i)->data);
    }
    printf("\n");
}

int main()
{
    Heap heap;
    
    initHeap(&heap, 10);
    assert(heap.numItems == 0);
    assert(heap.maxSize == 10);

    heapPush(&heap, 2);
    printHeap(&heap);
    heapPush(&heap, 1);
    printHeap(&heap);
    heapPush(&heap, 10);
    printHeap(&heap);
    heapPush(&heap, 0);

    printHeap(&heap);
    assert(heap.numItems == 4);
    assert(heap.maxSize == 10);

    int val1 = heapPop(&heap);
    int val2 = heapPop(&heap);
    int val3 = heapPop(&heap);
    int val4 = heapPop(&heap);
    printf("val1 %d\n", val1);
    printf("val2 %d\n", val2);
    printf("val3 %d\n", val3);
    printf("val4 %d\n", val4);
    printHeap(&heap);

    assert(val1 == 0);
    assert(val2 == 1);
    assert(val3 == 2);
    assert(val4 == 10);

    heapPush(&heap, 10);
    heapPush(&heap, 9);
    heapPush(&heap, 8);
    heapPush(&heap, 0);

    val1 = heapPop(&heap);
    val2 = heapPop(&heap);

    assert(val1 == 0);
    assert(val2 == 8);

    heapPush(&heap, 12);
    heapPush(&heap, 13);

    val1 = heapPop(&heap);
    val2 = heapPop(&heap);
    val3 = heapPop(&heap);
    val4 = heapPop(&heap);

    assert(val1 == 9);
    assert(val2 == 10);
    assert(val3 == 12);
    assert(val4 == 13);

    destructHeap(&heap);

    printf("All good!\n");
}