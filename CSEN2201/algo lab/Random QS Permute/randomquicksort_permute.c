#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;
float avg=0.0;
FILE* fp;
FILE* fp1;
int n;
int randompartition(int* arr,int left,int right)
{	int pivot=arr[left+rand()%(right-left+1)];
	int temp=pivot;
	pivot=arr[right];
	arr[right]=temp;
	int small=left;
	int large=right;
	while(small<=large)
	{	while(arr[small]<=pivot && small<=large)
		{	count++;
			small++;
		}
		while(arr[large]>pivot)
		{	count++;
			large--;
		}
		if(small<large)
		{	temp=arr[small];
			arr[small]=arr[large];
			arr[large]=temp;
		}
	}
	arr[left]=arr[large];
	arr[large]=pivot;
	return large;
}
void randomQuickSort(int* arr,int left,int right)
{	int k;
	if(left<right)
	{	k=randompartition(arr,left,right);
		randomQuickSort(arr,left,k-1);
		randomQuickSort(arr,k+1,right);
	}
}
void permute(int* arr,int left,int right)
{	int temp;
	int i,j;
	if(left==right)
	{	for(j=0;j<n;j++)
		{	fprintf(fp,"%d ",arr[j]);
		}
		fprintf(fp,"\n");
		return;
	}
	for(i=left;i<=right;i++)
	{	temp=arr[left];
		arr[left]=arr[i];
		arr[i]=temp;
		permute(arr,left+1,right);
		temp=arr[left];
		arr[left]=arr[i];
		arr[i]=temp;
	}
}
int main()
{	int *array,*array1,i=0,size,j;
	printf("Enter n:");
	int tempcount;
	scanf("%d",&n);
	srand(time(NULL));
	array1=(int*)malloc(sizeof(int)*n);
	array=(int*)calloc(n,sizeof(int));
	fp=fopen("permutegenerator.txt","w+");
	for(i=0;i<n;i++)
		array1[i]=i+1;
	permute(array1,0,n-1);
	fclose(fp);
	int f10=1;
	for(i=2;i<=n;i++)
		f10=f10*i;
	fp1=fopen("permuteoutput.txt","w+");
	fp=fopen("permutegenerator.txt","r+");
	int k=0;
	char temp;
	for(i=0;i<f10;i++)
	{	for(j=0;j<n;j++)
		{	fscanf(fp,"%d",&array[j]);
		}
		 //printf("%d ",tempcount-count);

		fscanf(fp,"%c",&temp);
		randomQuickSort(array,0,n-1);
	//	tempcount=count;
//		printf("%d ",count);
		for(k=0;k<n;k++)
		{	fprintf(fp1,"%d ",array[k]);
		}
		fprintf(fp1,"\n");
	}
	avg=(float)count;
	avg/=f10;
	printf("The average is:%f",avg);
}
