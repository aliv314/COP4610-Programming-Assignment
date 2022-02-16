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
    pqueue* newpq = (pqueue*)malloc(sizeof(pqueue));

    //initializes first element in queue
    newpq->size = 1;
    newpq->mHeap[0] = init;
    return newpq;
}

//simple swap method
void swap(int* one, int* two)
{
    int temp = *two;
    *two = *one;
    *one = temp;
}
//returns size of the pqueue
int size(pqueue* pq)
{
    return pq->size;
}
//n is the size of the elements 
//i is the index which is being percolated up
void percolate_up(pqueue* pq, int n, int i)
{
    int index, parent;
    
    index = i;
    parent = (index-1)/2; 
    while(pq->mHeap[index] > pq->mHeap[parent] && index > 0 && parent >= 0)
    {
        //swap takes place
        swap(&(pq->mHeap[index]), &(pq->mHeap[parent]));
        //index becomes the parent for the next loop
        index = parent;
        //parent is of parent calculated for next loop
        parent = (index-1)/2;
    }
}
//n = size of the array
//i = node at which to heapify
void percolate_down(pqueue* pq, int n, int i)
{
    int index, temp, left, right;
    index = i;
    temp = i;
    left = 2 * i + 1; //index left child
    right = 2 * i + 2; //index right child

    //condition 1 checks that left and right are within the heap size
    //condition 2 checks that either of the children are bigger than the parent
    while(right < n && left < n && (pq->mHeap[i] < pq->mHeap[left]|| pq->mHeap[i] < pq->mHeap[right]))
    {
        //finding biggest of i's parents
        if(pq->mHeap[left] > pq->mHeap[right])temp = left;
        else temp = right;
        swap(&(pq->mHeap[temp]), &(pq->mHeap[i]));
        //recalculate parent and children
        index = temp;
        left = 2 * temp + 1;
        right = 2 * temp + 2;
    }
}

void add(pqueue* pq, int val)
{
    if(size(pq) == 1000){
        printf("Cannot add more to the heap!");
        return;
    }
    if(size(pq) == 0){
        pq->mHeap[0] = val;
        pq->size++;
        return;
    }
    pq->mHeap[size(pq)] = val;
    pq->size++;
    
    //added to the bottom so it needs to be percolated up
    percolate_up(pq, size(pq), size(pq)-1);
}

int extract_max(pqueue* pq)
{
    //temp value for largest
    int maxNum = pq->mHeap[0];
    pq->mHeap[0] = pq->mHeap[pq->size-1];
    pq->size--;
    percolate_down(pq, size(pq), 0);
    return maxNum;
}

void print_pq(pqueue *pq)
{
    for(int i = 0; i < size(pq); i++)
    {
        printf("mHeap[%d] = %d\n", i, pq->mHeap[i]);
    }
        
}

void main()
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
    printf("Max number is %d\n", extract_max(testQ));
    print_pq(testQ);


    free(testQ);
}
