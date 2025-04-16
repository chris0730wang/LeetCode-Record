
#define MAX_CALLS 10000

typedef struct {
    int times[MAX_CALLS];
    int front;
    int rear;
} RecentCounter;


RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->front = 0;
    obj->rear = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->times[obj->rear++] = t;

    while (obj->times[obj->front] < t - 3000) {
        obj->front++;
    }

    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter* obj) {
    
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 
 * recentCounterFree(obj);
*/