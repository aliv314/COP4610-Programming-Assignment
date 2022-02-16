typedef struct node{
    int val;
    struct node* next; 
}node;

typedef struct{
    int size; 
    node* head;
    node* tail;
}queue;

queue* create_q(int init);
int is_empty(queue* q);
void enqueue(queue* q, int val);
int dequeue(queue* q);
int size(queue* q);
void print_q(queue* q);
void destroy_q(queue* q);