typedef struct{
    int size;
    int mHeap[1000];
}pqueue;

pqueue* create_pq(int init);
void swap(int* a, int* b);
void percolate_up(pqueue* pq, int n, int i);
void percolate_down(pqueue* pq, int n, int i);
void add(pqueue* pq, int val);
int extract_max(pqueue* pq);
int size(pqueue* pq);
void print_pq(pqueue *pq);

