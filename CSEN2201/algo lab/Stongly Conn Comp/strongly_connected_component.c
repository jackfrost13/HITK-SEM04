#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int time,k=0;
// A structure to represent a node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
    char color;
    int pi,d,f;
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};

//A structure to represent finish time
struct finish_time
{
    int vertex;
    int fin_tim;
};


// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =
        (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    //printf("Johnny %d  ",k);
    k++;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
    {
        graph->array[i].head = NULL;
        graph->array[i].color='W';
        graph->array[i].pi=-1; //here '-1' stands for NULL
        graph->array[i].d=-1;
        graph->array[i].f=-1;
    }

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    /*// Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;*/
    //printf("%d to %d\n",src,dest);
}

void dfs(struct Graph* graph, struct finish_time* ft)
{
    time=0;
    int i;
    for(i=0; i<graph->V; i++)
    {
        if(graph->array[i].color=='W')
            dfs_visit(graph,i,ft);
    }
}
void dfs_visit(struct Graph* graph, int u, struct finish_time* ft)
{
    time=time+1;
    //printf("\ntime=%d",time);
    graph->array[u].d=time;
    graph->array[u].color='G';
    struct AdjList v=graph->array[u];
    while(v.head!=NULL)
    {
        //graph->array[((v.head)->dest)].color
        if(graph->array[((v.head)->dest)].color=='W')
        {
            //((v.head)->dest).pi=u;
            graph->array[((v.head)->dest)].pi=u;
            dfs_visit(graph,(v.head)->dest,ft);
        }
        v.head=(v.head)->next;
    }

    graph->array[u].color='B';
    time=time+1;
    graph->array[u].f=time;
    ft[u].vertex=u;
    ft[u].fin_tim=time;
}

void swap(struct finish_time* xp, struct finish_time* yp)
{
    struct finish_time temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort - sorting in decreasing order
void bubbleSort(struct finish_time* ft, int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (ft[j].fin_tim < ft[j+1].fin_tim)
              swap(&ft[j], &ft[j+1]);

}

void dfs_transpose(struct Graph* graph, struct finish_time* ft)
{
    time=0;
    int i;
    for(i=0; i<graph->V; i++)
    {
        if(graph->array[ft[i].vertex].color=='W')
        {
            printf("Strongly connected component:  ");
            dfs_visit_transpose(graph,ft[i].vertex);
            printf("\n");
        }
    }
}

void dfs_visit_transpose(struct Graph* graph, int u)
{
    time=time+1;
    //printf("\ntime=%d",time);
    graph->array[u].d=time;
    graph->array[u].color='G';
    struct AdjList v=graph->array[u];
    while(v.head!=NULL)
    {
        //graph->array[((v.head)->dest)].color
        if(graph->array[((v.head)->dest)].color=='W')
        {
            //((v.head)->dest).pi=u;
            graph->array[((v.head)->dest)].pi=u;
            dfs_visit_transpose(graph,(v.head)->dest);
        }
        v.head=(v.head)->next;
    }

    graph->array[u].color='B';
    time=time+1;
    graph->array[u].f=time;
    printf("%d ",u);
}

// Driver program to test above functions
main()
{
    FILE *fp;
    fp=fopen("strong_connect_comp.txt","r");
    int V = 8;
    struct Graph* graph = createGraph(V);
    struct finish_time ft[V];
    /*addEdge(graph, 5, 2, 1);
    addEdge(graph, 5, 0, 1);
    addEdge(graph, 4, 0, 1);
    addEdge(graph, 4, 1, 1);
    addEdge(graph, 2, 3, 1);
    addEdge(graph, 3, 1, 1);
    printf("\n\n");*/
    int p,q,r;
    while(fscanf(fp,"%d %d %d",&p,&q,&r)!=EOF)
	{
	        addEdge(graph,p,q,r);
	}
	fclose(fp);
    dfs(graph,ft);
    printf("\n\n");
    int i;
    /*for(i=0;i<6;i++)
    {
        printf("ft[%d].vertex= %d, ft[%d].fin_tim= %d\n", i, ft[i].vertex, i, ft[i].fin_tim);
    }*/
    bubbleSort(ft,V);
    printf("\n\n");
    /*for(i=0;i<6;i++)
    {
        printf("ft[%d].vertex= %d, ft[%d].fin_tim= %d\n", i, ft[i].vertex, i, ft[i].fin_tim);
    }*/
    struct Graph* graph_transpose = createGraph(V);
    fp=fopen("strong_connect_comp.txt","r");
    while(fscanf(fp,"%d %d %d",&p,&q,&r)!=EOF)
	{
	        addEdge(graph_transpose,q,p,r);
	}
	dfs_transpose(graph_transpose,ft);


}
