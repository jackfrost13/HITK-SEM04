#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,*a,h,count=0,total=0;
int parent(int i)
{
	return i/2;
}

void heapify(int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int smallest,temp;
	if(left<=h && a[left]<a[i])
	{
		count++;
		smallest=left;
	} 
	else
		smallest=i;
	if(right<=h && a[right]<a[smallest])
	{
		count++;
		smallest=right;
	}
	if(smallest!=i)
	{
		temp=a[i];
		a[i]=a[smallest];
		a[smallest]=temp;
		heapify(smallest);
	}
}
void extract(FILE *fp)
{
	int min=a[0];
	a[0]=a[h];
	h--;
	heapify(0);
	fprintf(fp,"%d\t",min);

}

void insert(int key)
{
	h++;
	int i=h;
	while(i>0 && a[parent(i)]>key)
	{
		a[i]=a[parent(i)];
		i=parent(i);

	}
	a[i]=key;

}

int main()
{
	int i,j,m;
	int n,h;
	float avg=0.0;
	printf("\nEnter no of elements:\n");
	scanf("%d",&n);
	printf("No. of comparisons made to be made:\n");
	scanf("%d",&m);
	srand(time(NULL));
	for(j=0;j<m;j++)
	{
		FILE* fp=fopen("heap.txt","w");
		a=(int*)malloc(n*sizeof(int));
		long *flag=(long*)calloc(n,sizeof(long));
		h=-1;
		count=0;
		for(i=0;i<n;i++)
		{
			int r=1+rand()%n;
			if(flag[r-1]=1)
			{
				flag[r-1]=1;
				fprintf(fp,"%ld\t",r);
				insert(r);
			}
			else 
				i--;
		}
		fprintf(fp,"\nsorted:\n");
		for(i=0;i<n;i++)
			extract(fp);
		printf("\nNo of comparisons=%d",count);
		total=total+count;
		fclose(fp);
	}
	avg=total/m;	
	printf("\nAvg comp =%f",avg);
	return 0;
	
}
