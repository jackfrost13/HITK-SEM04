#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 100

struct node{
    int u, v, w;
    struct node *next;
};

void insert(struct node **adj, int v, int w){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> v = v;
    new_node -> w = w;
    new_node -> next = *adj;
    *adj = new_node;
}

struct pq_data{
    int v, key;
};

int pos[MAXN];

struct pq_data pq[MAXN];
int size = -1;

void swap(struct pq_data *a, struct pq_data *b){
    struct pq_data temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i){
    return (i - 1) / 2;
}

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

int empty(){
    if(size == -1)
        return 1;
    return 0;
}

void min_heapify(int i){
    int l = left(i);
    int r = right(r);
    int smallest = i;
    if(l <= size && pq[l].key < pq[smallest].key)
        smallest = l;
    if(r <= size && pq[r].key < pq[smallest].key)
        smallest = r;
    if(smallest != i){
        pos[pq[i].v] = smallest;
        pos[pq[smallest].v] = i;
        swap(&pq[i],&pq[smallest]);
        min_heapify(smallest);
    }
}

void build_min_heap(n){
    int i;
    size = n - 1;
    pos[0] = 0;
    pq[0].v = 0;
    pq[0].key = 0;
    for(i = 1; i < n; i++){
        pq[i].v = i;
        pq[i].key = INT_MAX;
        pos[i] = i;
    }
}

void decrease_key(int v, int key){
    int i = pos[v];
    pq[i].key = key;
    while(i > 0 && (pq[parent(i)].key > pq[i].key)){
        pos[pq[i].v] = parent(i);
        pos[pq[parent(i)].v] = i;
        swap(&pq[parent(i)], &pq[i]);
        i = parent(i);
    }
}

int extract_heap_minimum() {
    int minimum = pq[0].v;
    pos[pq[0].v] = size;
    pos[pq[size].v] = 0;
    pq[0] = pq[size];
    size--;
    min_heapify(0);
    return minimum;
}

int is_in_pq(int u){
    if(pos[u] <= size)
        return 1;
    return 0;
}

void prims(struct node **adj, int n, int src){
    int parent[n], key[n], v, w, i;
    for(i = 0; i < n; i++){
        parent[i] = -1;
        key[i] = INT_MAX;
    }
    build_min_heap(n);

    key[0] = 0;
    pos[0] = 0;

    while(!empty()){
        int u = extract_heap_minimum();
        struct node *itr;
        for(itr = adj[u]; itr != NULL; itr = itr -> next){
            v = itr -> v;
            if(is_in_pq(v) && (itr -> w < key[v])){
                key[v] = itr -> w;
                parent[v] = u;
                decrease_key(v, key[v]);

            }
        }
    }
    printf("\n\n We have the following tree: \n");
    for (i = 1; i < n; ++i)
        printf(" %d - %d\n", parent[i], i);
}

int main(){
    int n, m;
    int i;
    int u, v, w;
    scanf("%d %d", &n, &m);
    struct node *adj[n];
    struct node *itr;
    for(i = 0; i < n; i++)  adj[i] = NULL;
    for(i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        insert(&adj[u], v, w);
        insert(&adj[v], u, w);
    }
    printf("\n We have the following adjacency list: ");
    for(i = 0; i < n; i++){
        printf("\n %d", i);
        for(itr = adj[i]; itr != NULL; itr = itr -> next)
            printf(" -> (%d, %d)", itr -> v, itr -> w);
        printf(" -> NULL");
    }
    prims(adj, n, 0);
    return 0;
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/



