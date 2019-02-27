#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Edge
{
	int src, dest, weight;
};
struct Graph
{
	int V, E;
	struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
	graph->V = V;
	graph->E = E;
	graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
	return graph;
}
struct subset
{
	int parent;
	int rank;
};

void swap(struct Edge *x,struct Edge *y)
{	struct Edge* temp=(struct Edge*)malloc(sizeof(struct Edge));
	*temp=*x;
	*x=*y;
	*y=*temp;
}

int partition(struct Edge *arr,int left,int right)
{	struct Edge pivot=arr[left];
	struct Edge temp;
	int small=left;
	int large=right;
	while(small<=large)
	{	//count++;
		while(arr[small].weight<=pivot.weight && small<=large)
		{	//count++;
			small++;}
		while(arr[large].weight>pivot.weight)
		{	//count++;
			large--;}
		if(small<large)
		{	//count++;
			temp=arr[small];
			arr[small]=arr[large];
			arr[large]=temp;
		}
	}
	arr[left]=arr[large];
	arr[large]=pivot;
	return large;
}
void QuickSort(struct Edge* arr,int left,int right)
{	int k;
	if(left<right)	
	{	k=partition(arr,left,right);
		QuickSort(arr,left,k-1);
		QuickSort(arr,k+1,right);
	}
}

int find(struct subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

void KruskalMST(struct Graph* graph)
{
	int V = graph->V;
	struct Edge result[V]; 
	int e = 0; 
	int i = 0; 

	//qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
	QuickSort(graph->edge,0,graph->E-1);
	struct subset *subsets =
		(struct subset*) malloc( V * sizeof(struct subset) );

	int v;
	//makeset
	for (v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1)
	{
		struct Edge next_edge = graph->edge[i++];
		//findset
		int x = find(subsets, next_edge.src);
		int y = find(subsets, next_edge.dest);

		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);//union
		}
	}
	int sum =0;
	printf("Following are the edges in the constructed MST\n");
	for (i = 0; i < e; ++i)
	{
		printf("%d -- %d == %d\n", result[i].src, result[i].dest,result[i].weight);
		sum=sum+result[i].weight;
	}
	printf("\nMST = %d\n",sum);
	return;
}
int main()
{
	int V,E;
	FILE *fp;
	fp=fopen("krushkal_input_qs.txt","r");
	fscanf(fp,"%d",&V);
	fscanf(fp,"%d",&E);
//	int *u=(int *)calloc(V,sizeof(int));
//	int *v=(int *)calloc(E,sizeof(int));
//	int *w=(int *)calloc(E,sizeof(int));
	struct Graph* graph = createGraph(V, E);
	int i;
	for(i=0;i<E;i++)
	{	fscanf(fp,"%d %d %d\n",&graph->edge[i].src,&graph->edge[i].dest,&graph->edge[i].weight);
	}
	
	/*int mat[V][V];
	int i,j;
	for(i=0;i<V;i++)
	{
        	for(j=0;j<V;j++)
        	{
        		mat[i][j]=0;
        	}
	}
	i=0;
	while(fscanf(fp,"%d%d%d",&u[i],&v[i],&w[i])!=EOF)
	{
		graph->edge[i].src = u[i];
		graph->edge[i].dest = v[i];
		graph->edge[i].weight = w[i];
		mat[u[i]][v[i]]=w[i];
		i++;
	}
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			if(i==j)
			{
				printf("%d\t",mat[i][j]);
			}
			else if(mat[i][j]>0)
				printf("%d\t",mat[i][j]);
			else
				printf("inf\t");
		}
		printf("\n");
	}*/

	printf("\n\n");
	KruskalMST(graph);
	return 0;
}
