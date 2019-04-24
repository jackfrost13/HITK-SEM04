#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int heap_size = -1, sum = 0;
typedef struct list {
	int adjvertex, weight;
	struct list *next;
} node;
struct priority_queue {
	int vertex, key;
};
int min(int a, int b) {
	if (a <= b)	return a;
	return b;
}

void min_heapify(int n, struct priority_queue priq[n], int i) {
	int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
	if (left <= heap_size && priq[left].key < priq[smallest].key) 	smallest = left;
	if (right <= heap_size && priq[right].key < priq[smallest].key) 	smallest = right;
	if (smallest != i) {
		struct priority_queue temp = priq[i];
		priq[i] = priq[smallest];
		priq[smallest] = temp;
		min_heapify (n, priq, smallest);
	}
}
void decrease (int n, struct priority_queue priq[n], int v, int k) {
	int i, index;
	for (i = 0; i <= heap_size; i++) {
		if (priq[i].vertex == v) {
			index = i;
			break;
		}
	}
	priq[index].key = k;
	int parent = (index - 1) / 2;
	while (index > 0 && (priq[parent].key > priq[index].key)) {
		struct priority_queue temp1 = priq[parent];
		priq[parent] = priq[index];
		priq[index] = temp1;
		index = parent;
		parent = (index - 1) / 2;
	}
}

void insert_priq (int n, struct priority_queue priq[n], int v, int k) {
	if (heap_size >= n - 1)	printf ("Overflow\n");
	else {
		struct priority_queue temp;
		temp.vertex = v;
		temp.key = k;
		heap_size++;
		int index = heap_size;
		priq[index] = temp;
		int parent = (index - 1) / 2;
		while (index > 0 && priq[parent].key > priq[index].key) {
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
		printf ("%d %d ", temp -> adjvertex, temp -> weight);
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
void prim_mst (int n, node *adjlist[n]) {
	int i, keyweight[n], parent[n];
	struct priority_queue priq[n];
	for (i = 0; i < n; i++) {
		parent[i] = -1;
		keyweight[i] = INT_MAX;
	}
	keyweight[0] = 0;
	for (i = 0; i < n; i++) {
		insert_priq(n, priq, i, keyweight[i]);
	}
	while (!is_empty(n, priq)) {
		struct priority_queue temp_node = extract_min(n, priq);
		int src = temp_node.vertex;
		node *head = adjlist[src];
		while (head != NULL) {
			if (isinpriq(n, priq, head -> adjvertex) && keyweight[head -> adjvertex] > head -> weight) {
				keyweight[head -> adjvertex] = head -> weight;
				parent[head -> adjvertex] = src;
				decrease(n, priq, head -> adjvertex, keyweight[head -> adjvertex]);
			}
			head = head -> next;
		}
	}
	for (i = 1; i < n; i++) {
		printf ("Edge included : %d - %d, %d\n", parent[i], i, keyweight[i]);
		sum += keyweight[i];
	}
}

int main() {
	int n, i, j;
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
	prim_mst(n, adjlist);
	printf ("MST Cost : %d\n", sum);
	return 0;
}
