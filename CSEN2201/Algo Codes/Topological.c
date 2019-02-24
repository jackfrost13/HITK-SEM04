#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct list {
	struct list* next;
	int data;
} node;
int N;
int *visited;
node *head = NULL;
void ts_insert (int x) {
	node *temp = (node *) malloc (sizeof (node));
	temp -> data = x;
	if (head == NULL) {
		temp -> next = NULL;
		head = temp;
		return;
	}
	temp -> next = head;
	head = temp;
}
void print (node *adjlist[]) {
	int i;
	for (i = 0; i < N; i++) {
		node *temp = adjlist[i];
		printf ("%d -> ", i);
		while (temp != NULL) {
			printf ("%d ", temp -> data);
			temp = temp -> next;
		}
		printf ("\n");
	}
}
void dfs (node *adjlist [], int x) {
	if (visited[x] == 0) {
		printf ("%d node\n", x);
		visited[x] = 1;
		node *temp = adjlist[x];
		if (temp == NULL) {
			//printf ("%d node\n", x);
			ts_insert (x);
			return;
		}
		while (temp != NULL) {
			if (visited[temp -> data] == 0) {
				dfs(adjlist, temp -> data);
			}
			temp = temp -> next;
		}
		ts_insert (x);
	}
}
void insert (node * adjlist [], int i, int j) {
	node *temp = adjlist[i];
	if (temp == NULL) {
		//printf ("Hello %d", j);
		node *new = (node *) malloc (sizeof(node));
		new -> next = NULL;
		new -> data = j;
		//printf ("data : %d %d\n", i, new -> data);
		adjlist[i] = new;
		return;
	}
	while (temp -> next != NULL) {
		temp = temp -> next;
	}
	node *new = (node *) malloc (sizeof(node));
	new -> next = NULL;
	new -> data = j;
	temp -> next = new;
	//printf ("data : %d %d\n", i, temp -> data);
}

int main () {
	int i, j;
	scanf ("%d", &N);
	int adj[N][N];
	node *adjlist[N];
	visited = (int *) malloc (N * sizeof(int));
	memset (visited, 0, sizeof visited);
	for (i = 0; i < N; i++) {
		adjlist[i] = NULL;
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)  {
			scanf("%d", &adj[i][j]);
			if (adj[i][j] == 1) {
				insert(adjlist, i, j);
			}
		}
	}
	print(adjlist);
	for (i = 0; i < N; i++)
		dfs (adjlist, i);
	node *temp = head;
	while (temp != NULL) {
		printf ("%d ", temp -> data);
		temp = temp -> next;
	}
	return 0;
}
