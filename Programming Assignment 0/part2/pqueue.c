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
    //initializes first element in pq
    newpq->size = 1;
    newpq->m_heap[0] = init;
    return newpq;
}

//returns size of the pqueue
int size(pqueue* pq)
{
    return pq->size;
}

//methods to obtain the parent, the left, and the right nodes
int parentNode(int i){
    return ((i-1)/2); 
}

int leftNode(int i){
    return ((2*i)+1);
}

int rightNode(int i){
    return ((2*i)+2);
}

//simple swap method
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void percolate_down(pqueue* pq, int n, int i)
{
    int max, left, right;
    max = 0;
    left = leftNode(i);
    right = rightNode(i);    
    //conditions
    //child is within size
    //child is bigger than parent
    //find bigger of the two children
    if(right < n && pq->m_heap[right] > pq->m_heap[i] && pq->m_heap[right] > pq->m_heap[left]){
        max = right;
    }else if(left < n && pq->m_heap[left] > pq->m_heap[i]){
        max = left;
    }else{
        //neither child is bigger, stop
        return;
    }

    //swap because it didn't return
    swap(&pq->m_heap[i],&pq->m_heap[max]);
    //percolate down at next children
    percolate_down(pq,size(pq),max);
}

void add(pqueue* pq, int val)
{   
    int i = size(pq);
    pq->m_heap[i] = val;
    
    //checks to see if i is a valid index 
    //also checks to see if parent of i is smaller than i
    while(pq->m_heap[i] > pq->m_heap[parentNode(i)] && i!=0){
        //swap i with parent
        swap(&pq->m_heap[i], &pq->m_heap[parentNode(i)]);
        i = parentNode(i);
    }
    //increase size for new element
    pq->size++;
}

int extract_max(pqueue* pq)
{
    //temp value for largest
    int maxNum = pq->m_heap[0];
    //last value in pq is moved to pos 0 in array
    pq->m_heap[0] = pq->m_heap[size(pq)-1];
    //decrement size
    pq->size--;
    //percolate element down
    percolate_down(pq, size(pq), 0);
    return maxNum;
}

void print_pq(pqueue *pq)
{
    if(!size(pq)){
        printf("Priority Queue Empty!\n");
        return;
    }
    for(int i = 0; i < size(pq); i++)
    {
        printf("m_heap[%d] = %d\n", i, pq->m_heap[i]);
    }
        
}

void main()
{
    pqueue* m_heap = create_pq(0);

    for(int i = 1; i < 5; i+=10){
        add(m_heap, i);
        printf("===============================\n");
    }
    print_pq(m_heap);
    for(int i = 1; i < 5; i+=10){
        printf("Extracted: %d", extract_max(m_heap));
        printf("===============================\n");
    }
    print_pq(m_heap);
    
    free(m_heap);
}
