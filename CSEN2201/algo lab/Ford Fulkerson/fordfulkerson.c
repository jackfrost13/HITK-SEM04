
#include <stdio.h>
#include<limits.h>
int n,e,head,tail;

int min (int x, int y) {
    return x<y ? x : y;  
}


void enqueue (int color[],int q[],int x) {
    q[tail] = x;
    tail++;
    color[x] = 1; 
}
int dequeue (int color[],int q[]) {
    int x = q[head];
	
    head++;
    color[x] = 2;
    return x;
}

int bfs (int capacity[][n],int flow[][n],int pred[],int start, int target) {
    int u,v;
    int color[n];
    int q[n+2];
    for (u=0; u<n; u++) {
	color[u] = 0;
    }
    head = tail = 0;
    enqueue(color,q,start);
	
    pred[start] = -1;
    while (head!=tail) {
	u = dequeue(color,q);
		for (v=0; v<n; v++) {
	   		 if (color[v]==0 && capacity[u][v]-flow[u][v]>0) {
			enqueue(color,q,v);
			printf("%d ",u);		
			pred[v] = u;
				if(v==n-1)
				printf("%d",n-1);
	   		 }
		
		}
	
    }
    
    return color[target]==2;
}

//Ford-Fulkerson Algorithm
int max_flow (int capacity[][n],int flow[][n],int source, int sink) {
    int i,j,u;
    int pred[n]; 
       int max_flow = 0;
    for (i=0; i<n; i++) {
	for (j=0; j<n; j++) {
	    flow[i][j] = 0;
	}
    }
    while (bfs(capacity,flow,pred,source,sink))
	{
		int increment = INT_MAX;
		for (u=n-1; pred[u]>=0; u=pred[u]) {
		    increment = min(increment,capacity[pred[u]][u]-flow[pred[u]][u]);
		}
		for (u=n-1; pred[u]>=0; u=pred[u]) {
		    flow[pred[u]][u] += increment;
		    flow[u][pred[u]] -= increment;
		}
	
		printf("\n");
		max_flow += increment;
    }
    
    return max_flow;
}


int main ()
{
    int a,b,c,i,j,count=0,p;
    FILE *input;
    input=fopen("fordfulkerson_input.txt","r");
    while(fscanf(input,"%d",&p)!=EOF)
        count++;
    count=count-1;
    count/=3;
    e=count;//edges
    fclose(input);
    input=fopen("fordfulkerson_input.txt","r");
    // read number of nodes
    fscanf(input,"%d",&n);
    int capacity[n][n],flow[n][n];
    // initialize empty capacity matrix
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            capacity[i][j] = 0;
    // read edge capacities
    for (i=0; i<e; i++)
    {
        fscanf(input,"%d %d %d",&a,&b,&c);
        capacity[a][b] = c;
    }
    fclose(input);
    printf("Max flow of given flow network: %d\n",max_flow(capacity,flow,0,n-1));
    return 0;
}
