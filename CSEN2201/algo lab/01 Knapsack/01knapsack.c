#include<stdio.h>
#include<stdlib.h>
int max(int a,int b);
int knapsack(int W, int *wt, int **b, int *val, int n);
void print_items(int **b, int *wt, int N, int M);

int main()
{
	int N,M;
	int i,j;
	FILE *fp=fopen("data01.txt","r+");
	if(fp== NULL)
	{	printf("Cant open file\n");
		return;
	}
	fscanf(fp,"%d %d",&N,&M);//the first two values are the number of things present inside and the max wt that can be take. in this case 3 and 30 resp.
	int wt[N];
	int val[M];
	for(i=0;i<N;i++)
		fscanf(fp,"%d %d",&wt[i],&val[i]);
	fclose(fp);
	int **b;
	b=(int **)malloc(sizeof(int *)*(N+1));
	for(i=0;i<=N;i++)
		b[i]=(int*)malloc(sizeof(int)*(M+1));//forms a matrix b of size 4 * 31
	printf("Value : %d\n",knapsack(M,wt,b,val,N));//calls knapsack and prints the highest value possible for the weight to be 30.
	print_items(b,wt,N,M);//prints the items which are selected.
	for(i=0;i<=N;i++)//prints the b matrix
	{	for(j=0;j<=M;j++)
			printf("%2d ",b[i][j]);
	printf("\n");
	}
	
}

int max(int a,int b)
{	return((a>b)?a:b);
}

int knapsack(int W, int *wt, int **b, int *val, int n)
{	int i,w;
	for(i=0;i<=n;i++)
	{	for(w=0;w<=W;w++)
		{	if(i==0 || w==0)
				b[i][w]=0;
			else if(wt[i-1]<=w)
				b[i][w]=max(val[i-1]+b[i-1][w-wt[i-1]],b[i-1][w]);	
			else
				b[i][w]=b[i-1][w];
		}
	}
	return b[n][W];
}

void print_items(int **b, int *wt, int N, int M)
{	int i,k;
	i=N;
	k=M;
	while(i>0 && k>0)
	{	if(b[i][k]!=b[i-1][k])
		{	printf("ITEM %d\n",i);
			i--;
			k=k-wt[i];
		}
		else i--;
	}
}
	
					
