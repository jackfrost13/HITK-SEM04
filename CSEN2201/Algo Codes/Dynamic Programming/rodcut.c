#include<stdio.h> 
#include<limits.h> 
int max(int a, int b) { return (a > b)? a : b;} 
int cutRod(int price[], int n,int s[]) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j;
   for (i=1;i<=n;i++) 
   {
       int max_val=INT_MIN; 
       for (j=0;j<i;j++) 
	   {
			if(max_val<price[j]+val[i-j-1])
			{
				max_val=price[j]+val[i-j-1]; 
		 		s[i]=j+1;
			}
	   }
       val[i]=max_val;
   } 
   return val[n]; 
} 
void print_sol(int s[],int n)
{
	printf("cut at-");
	while(n>0)
	{
		printf("%d-",s[n]);
		n-=s[n];
	}
	printf("End\n");
}
int main() 
{ 
    int arr[] = {2, 5, 8, 9, 10, 17, 17, 20},i; 
	int arr1[] = {1,5,8,10,13,17,18,22,25,30};
	int size = sizeof(arr)/sizeof(arr[0]); 
	printf("\n\n***********\tSolution For 1st Rod \t***********\n");
	for(i=1;i<=size;i++)
	{
		int s[i];
		printf("For Length : %d\n",i);
    	printf("Maximum Obtainable Value : %d\n", cutRod(arr,i,s));
		print_sol(s,i); 
	}  
	printf("\n\n***********\tSolution For 2nd Rod \t***********\n");
	size = sizeof(arr1)/sizeof(arr1[0]);
	for(i=1;i<=size;i++)
	{
		int s[i];
		printf("For Length : %d\n",i);
    	printf("Maximum Obtainable Value : %d\n", cutRod(arr1,i,s));
		print_sol(s,i);
	}  
    return 0; 
} 
