#include<stdio.h>
#include<stdlib.h>
int top=-1;
struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
struct AdjList 
{
    struct AdjListNode *head;
};
struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
struct AdjListNode* newAdjListNode(int dest) 
{ 
    struct AdjListNode* newNode=(struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 
struct Graph createGraph(int V) 
{ 
    struct Graph graph; 
    graph.V=V;
    graph.array=(struct AdjList*)malloc(V*sizeof(struct AdjList));  
    int i; 
    for(i=0;i<V;++i) 
        graph.array[i].head=NULL; 
    return graph; 
} 
void addEdge(struct Graph graph, int src, int dest) 
{ 
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph.array[src].head; 
    graph.array[src].head = newNode; 
} 
void print_graph(struct Graph graph,int v)
{
    int i;
    for(i=0;i<v;i++)
    {
        struct AdjListNode* temp = graph.array[i].head;
        printf("%d",i);
        while(temp){
            printf("-->%d",temp->dest);
            temp=temp->next;
        }
        printf("\n");
    }
}
void topologicalSortUtil(struct Graph graph,int v, int visited[], int *stack) 
{  
	visited[v] = 1;  
	int i; 
	struct AdjListNode* temp = graph.array[v].head;
    while(temp)
    {
        if (!visited[temp->dest]) 		
            topologicalSortUtil(graph,temp->dest, visited, stack); 
        temp=temp->next;
    }
	stack[++top]=v; 
} 
void topologicalSort(struct Graph graph,int V,int *stack) 
{ 
	int *visited = (int*)calloc(V,sizeof(int)); 
	for (int i = 0; i < V; i++) 
	    if (!visited[i]) 
		    topologicalSortUtil(graph,i, visited, stack); 
	while (top!=-1) 
		printf("%d ",stack[top--]); 
} 

int main() 
{ 
	struct Graph g=createGraph(6); 
	addEdge(g, 5, 2); 
	addEdge(g, 5, 0); 
	addEdge(g, 4, 0); 
	addEdge(g, 4, 1); 
	addEdge(g, 2, 3); 
	addEdge(g, 3, 1); 
	print_graph(g, 6);
	int *s=(int*)calloc(6,sizeof(int));
	printf("Following is a Topological Sort of the given graph \n");
	topologicalSort(g,6,s);
	return 0; 
} 
