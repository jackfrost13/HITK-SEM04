#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int front = -1, rear = -1, **resadjmat, *vis;
void push (int n, int queue[n], int num) {
	if (front == -1 && rear == -1) {
		front++;
		rear++;
		queue[rear] = num;
	} else {
		rear++;
		queue[rear] = num;
	}
}
int pop(int n, int queue[n]) {
	int num = queue[front];
	front++;
	return num;
}
int isEmpty (int n, int queue[n]) {
	if (front == -1 || front > rear) return 1;
	return 0;
}
int bfs (int n, int src, int dest, int parent[n]) {
	int v, visited[n];
	memset(visited, 0, sizeof(visited));
	memset(parent, -1, sizeof (parent));
	int queue[n];
	visited[src] = parent[src] = 1;
	push(n, queue, src);
	while (!isEmpty(n, queue)) {
		int u = pop(n, queue);
		for (v = 0; v < n; v++) {
			if (!visited[v] && resadjmat[u][v] > 0) {
				visited[v] = 1;
				parent[v] = u;
				push(n, queue, v);
			}
		}
	}
	return visited[dest];
}

void Ford_Fulkerson(int n, int adjmat[n][n], int src, int dest) {
	int i, j, parent[n], max_flow = 0;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) resadjmat[i][j] = adjmat[i][j];
	while (bfs(n, src, dest, parent)) {
		int minpathflow = INT_MAX, v = dest;
		while (v != src) {
			int u = parent[v];
			if (resadjmat[u][v] < minpathflow)	minpathflow = resadjmat[u][v];
			v = u;
		}
		v = dest;
		while (v != src) {
			int u = parent[v];
			resadjmat[u][v]  -= minpathflow;
			resadjmat[v][u] += minpathflow;
			v = u;
		}
		max_flow += minpathflow;
	}
	printf ("Maximum flow of the graph : %d\n", max_flow);
}
void dfs (int n, int s) {
	vis[s] = 1;
	int i;
	for (i = 0; i < n; i++) {
		if (resadjmat[s][i] && !vis[i]) {
			dfs(n, i);
		}
	}
}
void mincut(int n, int src) {
	dfs(n, src);
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (vis[i] && !vis[j] && resadjmat[i][j])
				printf ("%d - %d\n", i, j);
		}
	}
}
int main() {
	int n, i, j;
	scanf ("%d", &n);
	resadjmat = (int **) malloc (n * sizeof (int *));
	int adjmat[n][n];
	vis = (int *) malloc (n * sizeof(int));
	for (i = 0; i < n; i++)	{
		vis[i] = 0;
		resadjmat[i] = (int *) malloc (n * sizeof (int));
	}
	for (i = 0; i < n; i++) for (j = 0; j < n; j++)	scanf ("%d", &adjmat[i][j]);
	int src, dest;
	scanf ("%d %d", &src, &dest);
	Ford_Fulkerson(n, adjmat, src, dest);
	mincut (n, src);
	return 0;
}
