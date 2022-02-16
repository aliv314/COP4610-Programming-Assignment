#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

/*
(20 points) Implement the priority queue ADT using a max binary heap in C. 
To do this, you need to implement functions 
add (for adding an element of type int to the heap), 
extract_max (for removing the greatest element stored in the heap), 
size (for returning the number of elements in the heap). 
Please test your implementation extensively to be sure about its correctness. 
You need to submit the C program containing you test cases along the heap implementation.
*/

pqueue* create_pq(int init)
{
    pqueue *newpq = malloc(sizeof(newpq));

    //pqueue newpq;
    newpq->size = 0;
    add(newpq, init);
    return newpq;
}

void heapify(pqueue* pq, int n, int i)
{
    int largest = i;

    int l = 2 * i + 1; //left child
    int r = 2 * i + 2; //right child

    if (l < n && pq->mHeap[largest] < pq->mHeap[l])
        largest = l;

    if (r < n && pq->mHeap[largest] < pq->mHeap[r])
        largest = r;

    if(largest != i)
    {
        int temp = pq->mHeap[i];
        pq->mHeap[i] = pq->mHeap[largest];
        pq->mHeap[largest] = temp;

        heapify(pq, n, largest);
    }
    
}

void add(pqueue* pq, int val)
{
    int temp = pq->mHeap[1];
    pq->mHeap[1] = val;
    pq->mHeap[size(pq)] = temp;
    pq->size = pq->size + 1;
    
    heapify(pq, size(pq), 0); //call heapify
}

int extract_max(pqueue* pq) //unfinished
{
    int maxNum = pq->mHeap[0];
    pq->mHeap[0] = 0;
    heapify(pq, size(pq), 0);
    return maxNum;
}

int size(pqueue* pq)
{
    return pq->size;
}

void print_pq(pqueue *pq)
{
    for(int i = 0; i < size(pq); i++)
    {
        printf("mHeap[%d] = %d\n", i, pq->mHeap[i]);
    }
        
}
int main()
{
     pqueue *testQ = create_pq(7);
     add(testQ,6);
     add(testQ,8);
     add(testQ,5);
     add(testQ,9);
     add(testQ,1);
     print_pq(testQ);
     printf("Max number is %d\n", extract_max(testQ));
     print_pq(testQ);

    free(testQ);
    return 0;
}
