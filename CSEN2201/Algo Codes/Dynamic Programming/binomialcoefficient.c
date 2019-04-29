#include<stdio.h> 
int min(int a, int b); 
int binomialCoeff(int n, int k) 
{ 
    int C[n + 1][n+1]; 
    int i, j; 
    for (i = 0; i <= n; i++) 
    { 
        for (j = 0; j <=n; j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + 
                          C[i - 1][j]; 
        } 
    } 
    return C[n][k]; 
}  
int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
} 
int main() 
{	
	char c="y";
	do
	{
		int n,k;
		printf("Enter n : ");
		scanf("%d",&n);
		printf("Enter k : ");
		scanf("%d",&k); 
		printf("Value of C[%d][%d] is %d\n",n,k,binomialCoeff(n, k)); 
		printf("Do you want to continue (Y/N) : ");
		scanf("%c",&c);
		c=getchar();
	}while(c==89 || c==121);
} 
