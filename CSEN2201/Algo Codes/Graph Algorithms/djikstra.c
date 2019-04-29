#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void printPath(int parent[], int j) 
{  
    if (parent[j] == - 1) 
        return; 
    printPath(parent, parent[j]); 
  
    printf("%d ", j); 
} 
int printSolution(int dist[], int n,  int parent[]) 
{ 
    int src = 0; 
    printf("Vertex\t Distance\t\tPath"); 
    for (int i = 1; i < n; i++) 
    { 
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src); 
        printPath(parent, i); 
    } 
} 
int minDistance(int dist[], int visited[],int n) 
{ 
	int min=INT_MAX,min_index,i=0; 
	for(i=0;i<n;i++) 
	{
		if (!visited[i] && dist[i] <= min)
		{ 
			min = dist[i]; 
			min_index = i; 
		}
	}
	return min_index; 
} 
void djikstra (int graph[9][9],int n,int src) 
{
	int i, dist[n], visited[n] ,j ,parent[n];
	for (i = 0; i < n; i++) 
	{
		visited[i] = 0;
		dist[i] = INT_MAX;
	}
	dist[src] = 0;	
	parent[src]=-1;
	for (i=0;i<n;i++) 
	{ 
		int u=minDistance(dist,visited,n); 
		visited[u] = 1; 
		for (j = 0; j < n; j++) 
			if (!visited[j] && graph[u][j] && dist[u]!= INT_MAX && dist[u]+graph[u][j] < dist[j]) 
			{
				dist[j] = dist[u] + graph[u][j];
				parent[j]=u;
			} 
	} 
	for (i = 1; i < n; i++) 
		printf ("Shortest distance from %d to %d is = %d\n", src, i, dist[i]);
	printSolution(dist, n, parent);
	printf ("\n");
}

int main() {
	int n,i,j;
	//scanf ("%d", &n);
	int graph[9][9] ={{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
					{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
					{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
					{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
					{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
					{0, 0, 4, 14, 10, 0, 2, 0, 0}, 
					{0, 0, 0, 0, 0, 2, 0, 1, 6}, 
					{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
					{0, 0, 2, 0, 0, 0, 6, 7, 0} 
					};
	djikstra(graph,9,0);
	return 0;
}
