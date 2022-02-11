typedef struct{
    int size;
    int mHeap[10000];
}pQueue;

pQueue* create_pQ(int init);
void add(pQueue* pQ, int val);
int extract_max(pQueue* pQ);
int size(pQueue* pQ);
void destroy_pQ(pQueue* pQ);