typedef struct{
    int size;
    int m_heap[1000];
}pqueue;

pqueue* create_pq(int init);
void swap(int* a, int* b);
int size(pqueue* pq);
int parent(int i);
int left(int i);
int right(int i);
void percolate_down(pqueue* pq, int n, int i);
void add(pqueue* pq, int val);
int extract_max(pqueue* pq);

void print_pq(pqueue *pq);

