#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{ return a>b?b:a; }  
void print_table(int **t,int a,int b)
{
	int i,j;
	printf("A : %d B : %d\n",a,b);
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("%d  ",t[i][j]);
		}
		printf("\n");
	}
}
void print_Coin(int R[],int m,int n,int S[]) 
{
        if (R[n-1]==-1) 
		{
			printf("No solution is possible");
            return;
        }
        int start=n-1;
		printf("Coins used to form total ");
        while(start!=0) 
		{
            printf("%d +  ",S[R[start]]);
            start = start - S[R[start]];
        }
        printf("\n");
}
int count( int S[], int m, int n) 
{ 
    int i, j, x, y;
    int **table,R[n+1];
	table=(int**)calloc(m,sizeof(int*));
	for(i=0;i<m;i++)
		table[i]=(int*)calloc(n+1,sizeof(int));  
    for (i=0; i<n+1; i++) 
        table[0][i]=(int)i/S[0]; 
    for (i=1;i<m;i++) 
    { 
        for (j=0; j<n+1; j++) 
        { 
			if(j>=S[i])
			{
				table[i][j]=min(table[i-1][j],1+table[i][j-S[i]]);
				if(table[i][j]==1+table[i][j-S[i]])
				{
					R[j]=i;
				}
			}
			else
			{
				table[i][j]=table[i-1][j];
			}
        } 
    } 
	print_table(table,m,n+1);
	print_Coin(R,m,n+1,S);
    return table[m-1][n]; 
} 
int main() 
{ 
    int arr[] = {1,2,3,4,5,6,10}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 10; 
    printf(" %d ", count(arr, m, n)); 
    return 0; 
} 
