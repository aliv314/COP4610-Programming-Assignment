typedef struct{
    int val;
    Node* next; 
}Node;

typedef struct{
    Node* head;
    Node* tail;
}Queue;

Queue* create_q(int init);
int is_empty(Queue* q);
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
int get_head(Queue* q);
int get_tail(Queue* q);
void print_q(Queue* q);
int size(Queue* q);
void destroy_q(Queue* q);