typedef struct{
    int val;
    Node* next; 
}Node;

typedef struct{
    Node* head;
    Node* tail;
}Queue;

Queue* createQ(int init);
int isEmpty(Queue* q);
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
int getHead(Queue* q);
int getTail(Queue* q);
void printQ(Queue* q);
int size(Queue* q);
void destroyQ(Queue* q);