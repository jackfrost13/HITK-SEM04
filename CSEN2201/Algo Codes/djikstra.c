#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int heap_size = -1;
typedef struct list {
	int adjvertex, weight;
	struct list *next;
} node;
struct priority_queue {
	int vertex, dist;
};
int min(int a, int b) {
	if (a <= b)	return a;
	return b;
}

void min_heapify(int n, struct priority_queue priq[n], int i) {
	int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
	if (left <= heap_size && priq[left].dist < priq[smallest].dist) 	smallest = left;
	if (right <= heap_size && priq[right].dist < priq[smallest].dist) 	smallest = right;
	if (smallest != i) {
		struct priority_queue temp = priq[i];
		priq[i] = priq[smallest];
		priq[smallest] = temp;
		min_heapify (n, priq, smallest);
	}
}
void decrease (int n, struct priority_queue priq[n], int v, int d) {
	int i, index;
	for (i = 0; i <= heap_size; i++) {
		if (priq[i].vertex == v) {
			index = i;
			break;
		}
	}
	priq[index].dist = d;
	int parent = (index - 1) / 2;
	while (index > 0 && (priq[parent].dist > priq[index].dist)) {
		struct priority_queue temp1 = priq[parent];
		priq[parent] = priq[index];
		priq[index] = temp1;
		index = parent;
		parent = (index - 1) / 2;
	}
}

void insert_priq (int n, struct priority_queue priq[n], int v, int d) {
	if (heap_size >= n - 1)	printf ("Overflow\n");
	else {
		struct priority_queue temp;
		temp.vertex = v;
		temp.dist = d;
		heap_size++;
		int index = heap_size;
		priq[index] = temp;
		int parent = (index - 1) / 2;
		while (index > 0 && priq[parent].dist > priq[index].dist) {
			struct priority_queue temp1 = priq[parent];
			priq[parent] = priq[index];
			priq[index] = temp1;
			index = parent;
			parent = (index - 1) / 2;
		}
	}
}
struct priority_queue extract_min(int n, struct priority_queue priq[n]) {
	if (heap_size < 0)	printf ("Underflow\n");
	else {
		int index = heap_size;
		struct priority_queue temp = priq[0], min_node = priq[0];
		priq[0] = priq[index];
		priq[index] = temp;
		heap_size--;
		min_heapify(n, priq, 0);
		return min_node;
	}
}
int is_empty(int n, struct priority_queue priq[n]) {
	if (heap_size < 0)	return 1;
	return 0;
}

node *insert (node *head, int v, int w) {
	node *new_node = (node *) malloc (sizeof(node));
	new_node -> adjvertex = v;
	new_node -> weight = w;
	new_node -> next = NULL;
	if (head == NULL) {
		head = new_node;
	}else {
		node *temp = head;
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = new_node;
	}
	return head;
}

void display(node *head) {
	node *temp = head;
	if (temp == NULL) {
		printf ("No vertices are adjacent!\n");
		return;
	}
	while (temp != NULL) {
		printf ("%d (%d) ", temp -> adjvertex, temp -> weight);
		temp = temp -> next;
	}
	printf ("\n");
}
int isinpriq (int n, struct priority_queue priq[n], int v) {
	int i;
	for (i = 0; i <= heap_size; i++) {
		if (priq[i].vertex == v) return 1;
	}
	return 0;
}
void print_path (int n, int parent[n], int source, int dest) {
	if(parent[dest] == -1 && dest == source) {
		return;
	} else {
		print_path(n, parent, source, parent[dest]);
		printf ("%d ", parent[dest]);
	}
}
void djikstra (int n, node *adjlist[n], int src) {
	int i, distance[n], parent[n];
	struct priority_queue priq[n];
	for (i = 0; i < n; i++) {
		parent[i] = -1;
		distance[i] = INT_MAX;
	}
	distance[src] = 0;
	for (i = 0; i < n; i++) {
		insert_priq(n, priq, i, distance[i]);
	}
	while (!is_empty(n, priq)) {
		struct priority_queue temp_node = extract_min(n, priq);
		int srcvertex = temp_node.vertex, srcweight = temp_node.dist;
		node *head = adjlist[srcvertex];
		while (head != NULL) {
			if (distance [head -> adjvertex] > srcweight + head -> weight) {
				distance [head -> adjvertex] = srcweight + head -> weight;
				parent[head -> adjvertex] = srcvertex;
				decrease(n, priq, head -> adjvertex, distance[head -> adjvertex]);
			}
			head = head -> next;
		}
	}
	for (i = 1; i < n; i++) {
		printf ("Shortest distance from %d to %d is = %d\n", src, i, distance[i]);
		printf ("Shortest Path : \n");
		print_path(n, parent, src, i);
		printf ("%d\n", i);
	}
	printf ("\n");
}

int main() {
	int n, i, j, sc;
	scanf ("%d", &n);
	int adjmat[n][n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &adjmat[i][j]);
		}
	}
	node *adjlist[n];
	for (i = 0; i < n; i++)  adjlist[i] = NULL;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n ; j++) {
			if (adjmat[i][j] != 0) 	adjlist[i] = insert (adjlist[i], j, adjmat[i][j]);
		}
	}
	printf ("Adj list : \n");
	for (i = 0; i < n; i++) {
		printf ("%d -> ", i);
		display(adjlist[i]);
	}
	scanf ("%d", &sc);
	djikstra(n, adjlist, sc);
	return 0;
}
