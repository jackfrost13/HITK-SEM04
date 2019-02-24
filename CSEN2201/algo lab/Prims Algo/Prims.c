#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
	int vertex;
	int wt;
	struct node *next;
}node;

typedef struct graph
{
	int n;
	node **head;
}graph;

typedef struct queue
{
	int n;
	int N;
	int *arr[2];
}queue;

graph init_graph();
void insert_vertex(node **, int , int, int);
void print_graph(graph g);
void prims(graph, int **, int **, int);
int in_queue(int, queue *);

queue init_queue(int *, int);
void min_heapify(queue *, int);
void build_heap(queue *);
int extract_min(queue *);

void print_edges(int n, int *pred, int *dist);

int main()
{
	graph g = init_graph();
	int *pred, *dist;
	print_graph(g);

	int source, i;
	printf("Enter the source >> ");
	scanf("%d", &source);
	
	prims(g, &pred, &dist, source);
	
	for(i = 1; i <= g.n; i++)
	{
		printf("%4d : %4d %4d\n", i, pred[i], dist[i]);
	}
	printf("\n");
	print_edges(g.n, pred, dist);
	printf("\n");
	
	return 0;
}

graph init_graph()
{
	graph g;
	FILE *fp;
	node *n;
	int u, v, w, i;
	
	fp = fopen("list.data", "r");

	fscanf(fp, "%d", &g.n);
	g.head = malloc(g.n * sizeof(node *));
	
	for(i = 0; i < g.n; i++)
		g.head[i] = NULL;

	while(!feof(fp))
	{
		fscanf(fp, "%d %d %d ", &u, &v, &w);
		insert_vertex(g.head, u, v, w);
	}
	return g;
}

void insert_vertex(node **h, int u, int v, int w)
{
	node *new_node = malloc(sizeof(node));

	new_node -> vertex = v;
	new_node -> wt = w;
	new_node -> next = NULL;

	if(h[u-1] == NULL)
	{
		h[u-1] = new_node;
		return;
	}
	new_node -> next = h[u-1];
	h[u-1] = new_node;
}

void print_graph(graph g)
{
	node *curr;
	int i;
	
	for(i = 0; i < g.n; i++)
	{
		curr = g.head[i];
		printf("%d -> ", i+1);
	
		while(curr != NULL)
		{
			printf("%d, %d -> ", curr->vertex, curr->wt);
			curr = curr->next;
		}
		printf("\n");
	}
}

void prims(graph g, int **pred, int **dist, int source)
{
		int i, u;
		node *vertex;
		queue Q;

		*pred = malloc((g.n+1) * sizeof(int));
		*dist = malloc((g.n+1) * sizeof(int));

		for(i = 1; i <=g.n; i++)
		{
			(*pred)[i] = -1;
			(*dist)[i] = INT_MAX;
		}
		(*dist)[source] = 0;
	
		Q = init_queue(*dist, g.n);//
		build_heap(&Q);

		while(Q.n)
		{
			u = extract_min(&Q);
			vertex = g.head[u-1];
			while(vertex != NULL)
			{
				int V = in_queue(vertex->vertex, &Q);
				if(V && vertex->wt < (*dist)[vertex->vertex])
				{
					(*pred)[vertex->vertex] = u;
					(*dist)[vertex->vertex] = vertex->wt;
	
					Q.arr[1][V] = vertex->wt;
				}
				build_heap(&Q);
				vertex = vertex -> next;
			}
			
		}
}

int in_queue(int v, queue *Q)
{
		int i;
		
		for(i = 1; i <= Q->n; i++)
		{
			if(Q -> arr[0][i] == v)
			{
				return i;
			}
		}
		return 0;
}

queue init_queue(int *d, int n)
{
	queue Q;
	Q.n = n;
	Q.N = n;
	int i;
	
	for(i = 0; i < 2; i++)
		Q.arr[i] = malloc((n+1)*sizeof(int));
		
	for(i = 1; i <= n; i++)
	{
		Q.arr[0][i] = i;
		Q.arr[1][i] = d[i];
	}
	return Q;
}

void min_heapify(queue *Q, int i)
{
	int left = 2*i;
	int right = 2*i + 1;

	int min;
	
	if(left <= Q->n && Q -> arr[1][left] < Q -> arr[1][i])
		min = left;
	else
		min = i;
	
	if(right <= Q->n && Q -> arr[1][right] < Q -> arr[1][min])
		min = right;
	
	if(min != i)
	{
		int temp0 = Q -> arr[0][min];
		int temp1 = Q -> arr[1][min];
	
		Q -> arr[0][min] = Q -> arr[0][i];
		Q -> arr[1][min] = Q -> arr[1][i];
		
		Q -> arr[0][i] = temp0;
		Q -> arr[1][i] = temp1;

		min_heapify(Q, min);
	}
}

int extract_min(queue *Q)
{
	if(Q -> n == 0)
		return -1;
	
	int min = Q -> arr[0][1];
	
	int temp0 = Q -> arr[0][1];
	int temp1 = Q -> arr[1][1];
	
	Q -> arr[0][1] = Q -> arr[0][Q->n];
	Q -> arr[1][1] = Q -> arr[1][Q->n];

	Q -> arr[0][Q->n] = temp0;
	Q -> arr[1][Q->n] = temp1;

	Q -> n = Q -> n -1;
	
	min_heapify(Q, 1);
	
	return min;
}

void build_heap(queue *Q)
{
	int i;
	
	for(i = Q -> n/2; i >= 1; i--)
	{
		min_heapify(Q, i);
	}
}

void print_edges(int n, int *pred, int *dist)
{
	int i;
	int u, v, w;
	int sum = 0;
	
	for(i = 1; i <= n; i++)
	{
		u = i;
		v = pred[u];
		
		if(v > 0)
		{
			w = dist[u];
			printf("%d - %d , wt : %d\n", v, u, w);
			sum = sum + w;
		}
	}
	printf("COST :: %d\n", sum);
}


































