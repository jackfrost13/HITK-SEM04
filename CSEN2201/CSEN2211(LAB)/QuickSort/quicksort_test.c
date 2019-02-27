#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
int partition(int* arr,int left,int right)
{	int pivot=arr[right],temp;
	int small=left,i;
	int large=right;
	
		for(i=left;i<right;i++)
		{	if(arr[i]<=pivot)
			{
				temp=arr[small];
				arr[small]=arr[i];
				arr[i]=temp;
				small++;
			}	
	}
	temp=arr[small];
	arr[small]=arr[large];
	arr[large]=temp;
	
	return small;
}
void QuickSort(int* arr,int left,int right)
{	int k;
	if(left<right)	
	{	k=partition(arr,left,right);
		QuickSort(arr,left,k-1);
		QuickSort(arr,k+1,right);
	}
}
int main()
{	FILE* fp;
	int n,*array,i=0,j;
	fp=fopen("data.txt","r+");
	printf("Enter number of elements\n");
	scanf("%d",&n);
	array=(int*)calloc(n,sizeof(int));	
	while(i<n+1)
	{	fscanf(fp,"%d",&array[i]);
		i++;
	}
	printf("\n");
	QuickSort(array,0,n-1);
	for(j=0;j<n;j++)
	{	printf("%d ",array[j]);
	}
	printf("\nThe number of comparisons:%d",count);
}
		






