#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
(10 points) Implement the queue ADT (FIFO) using a linked list in C. 
To do this, you need to implement functions 
enqueue (for adding an element of type int to the rear end of queue), 
dequeue (for removing an element of type int from the front end of the queue),
size (for returning the number of elements in the queue). 
Please test your implementation extensively to be sure about its correctness. 
You need to submit the C program containing you test cases along the queue implementation.
*/

queue* create_q(int init){
    queue* q = (queue*)malloc(sizeof(queue));
    node* n = (node*)malloc(sizeof(node));
    //initialize first node
    n->val = init;
    q->size = 1;
    q->head = n;
    q->tail = q->head;
    q->head->next = NULL;
    return q;
}

int is_empty(queue* q){
    if(q->head == NULL) return 1;
    return 0;
}

void enqueue(queue* q, int val){
    node* new = (node*)malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    //if it's empty, new node is the head
    if(is_empty(q)){
        q->head = new;
        q->tail = q->head;
        q->size = 1;
        return;
    }
    q->tail->next = new;
    q->tail = new;
    q->size++;
}

int dequeue(queue* q){
    //can't deque
    if(is_empty(q)){
        printf("ERROR. Queue is empty. Returned -1.\n");
        return -1;
    };
    
    //temp int needed to store return
    int val = 0;
    val = q->head->val;
    
    node* temp = q->head;
    q->head = q->head->next;
    q->size--;
    //free dequeued node
    free(temp);
    return val;
}

void print_q(queue* q){
    //empty queue
    if(is_empty(q)){
        printf("Queue is empty.\n");
        return;
    }
    //temp pointer to go through queue
    node* n = q->head;
    printf("Queue contains: ");
    while(n != NULL){
        printf("[%d]-> ", n->val);
        n = n->next;
    }
    printf("NULL \n");
}

int size(queue* q){
    if(is_empty(q)) return 0;
    return q->size;
}

void destroy_q(queue* q){
    //queue isn't destroyed when emptied
    if(is_empty(q)){
        free(q);
        return;
    }
    //called recursively
    dequeue(q);
    destroy_q(q);
}

void main(){
    queue* q = create_q(1);
    for(int i = 2; i < 21; i++){
        enqueue(q, i);
    }
	printf("Queue size: %d\n", size(q));
    print_q(q);

    int arr [20]; 
    for(int i = 0; i < 20; i++){
        arr[i] = dequeue(q);
    }
    for(int i = 0; i < 20; i++){
        printf("Array position [%d] = %d \n", i, arr[i]);
    }  
    print_q(q);
	printf("Queue size: %d\n", size(q));
}
