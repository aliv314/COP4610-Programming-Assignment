typedef struct{
    int size;
    int mHeap[10000];
}pqueue;

pqueue* create_pq(int init);
void heapify(pqueue* pq, int n, int i);
void add(pqueue* pq, int val);
int extract_max(pqueue* pq);
int size(pqueue* pq);
void print_pq(pqueue *pq);

