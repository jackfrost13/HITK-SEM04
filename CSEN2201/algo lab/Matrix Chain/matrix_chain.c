#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int stat_no;
int **s,**m;
int matrixchainorder(int p[],int n)
{	int i,j,k,L,q;
	for(i=0;i<n;i++)
		m[i][i]=0;
	for(L=2;L<n;L++)
	{	for(i=1;i<n-L+1;i++)
		{	j=i+L-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j;k++)
			{	q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	return m[1][n-1];
}
void print_optimal(int i,int j)
{	if(i==j)
		printf("A%d",i);
	else
	{	printf("(");
		print_optimal(i,s[i][j]);
		print_optimal(s[i][j]+1,j);
		printf(")");
	}
}
int main()
{	int i,j,n,size;
	printf("Enter number of matrix:\n");
	scanf("%d",&n);
	size=n+1;
	int *arr;
	arr=(int*)calloc(size,sizeof(int));
	printf("Enter the dimensions:\n");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	s=(int**)calloc(size+1,sizeof(int *));
	for(i=0;i<size+1;i++)
		s[i]=(int *)calloc(size+1,sizeof(int));
	m=(int**)calloc(size+1,sizeof(int*));
	for(i=0;i<size+1;i++)
		m[i]=(int*)calloc(size+1,sizeof(int));
	printf("\nMin number of mul:%d\n",matrixchainorder(arr,size));
	printf("\nOptimal parenthesis is\n");
	print_optimal(1,size-1);
	printf("\nThe matrix is:\n");
        for(i=1;i<size;i++)
        {       for(j=1;j<size;j++)
                {        if(j<i)
                        {       printf("\t");

                        }
                        else
                        {       printf("%d\t",m[i][j]);
                        }
                }
                printf("\n");
        }

	printf("\n M matrix :\n");
	for(i=1;i<size;i++)
	{	for(j=1;j<size;j++)
		{	if(j<i)
			{	printf("\t");
			}
			else
			{	printf("%d\t",s[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}

