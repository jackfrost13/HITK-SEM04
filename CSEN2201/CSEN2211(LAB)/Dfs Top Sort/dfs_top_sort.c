#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int time,k=0,flag=0;

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

//A structure for the linked list that stores vertices according to finish time.
struct node
{
    int data;
    struct node* next;
};

//Creating the linked list globally
struct node* head1=NULL;

// A utility function to add a new node in the front of the linked list
void insert_first(struct node **head, int value)
{
    struct node *new_node = (struct node*) malloc (sizeof (struct node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

// A utility function to print the linked list
void print_linked_list(struct node* head)
{
    struct node* current = head;  // Initialize current
    while (current != NULL)
    {
        printf("%d-> ",current->data);
        current = current->next;
    }
}

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =
        (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    //printf("Johnny %d  ",k);
    //k++;
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
    printf("%d to %d\n",src,dest);
}

void dfs(struct Graph* graph)
{
    time=0;
    int i;
    for(i=0; i<graph->V; i++)
    {
        if(graph->array[i].color=='W')
            dfs_visit(graph,i);
    }
}
void dfs_visit(struct Graph* graph, int u)
{
    time=time+1;
    //printf("\ntime=%d",time);
    graph->array[u].d=time;
    graph->array[u].color='G';
    struct AdjList v=graph->array[u];
    while(v.head!=NULL)
    {
	if(graph->array[((v.head)->dest)].color=='G')
	{		
		printf("DFS stopped due to back edge detection.\n Thus graph is cyclic\n");
		exit(1);       
	} 
	
	//graph->array[((v.head)->dest)].color
        if(graph->array[((v.head)->dest)].color=='W')
        {
            //((v.head)->dest).pi=u;
            graph->array[((v.head)->dest)].pi=u;
            dfs_visit(graph,(v.head)->dest);
        }
        v.head=(v.head)->next;
    }

    graph->array[u].color='B';
    time=time+1;
    graph->array[u].f=time;
    insert_first(&head1, u);
}

// Driver program to test above functions
main()
{
    FILE *fp;
    fp=fopen("dfs_input.txt","r");
	// create the graph given in above fugure
    int V = 8;
    struct Graph* graph = createGraph(V);
    int p,q,r;
    while(fscanf(fp,"%d %d %d",&p,&q,&r)!=EOF)
	{
	        addEdge(graph,p,q,r);
	}
    fclose(fp);
    printf("\n\n");
    dfs(graph);
    printf("\n\n");
    print_linked_list(head1);

}
