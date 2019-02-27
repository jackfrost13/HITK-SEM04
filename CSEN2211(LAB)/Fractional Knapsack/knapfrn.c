#include<stdio.h>
#include<stdlib.h>
int num;
int *weight;
int *indexof;
int *profit;
float *ratio,*x;
float capacity;
void sort();
void knapsack();
int main(){
	FILE* fp;
	fp=fopen("knapsack.txt","r+");
	int i,j,a;
	i=0;
	while(fscanf(fp,"%d",&a)!=EOF)
	{
		if(i==0)
		{
			num=a;
			weight=(int *)malloc(num*sizeof(int));
        		profit=(int *)malloc(num*sizeof(int));
        		ratio=(float *)malloc(num*sizeof(float));
			indexof=(int *)malloc(num*sizeof(int));
		}
		else if(i==1)
		{
			capacity=a;
		}
		else if(i==2)
		{
			for(j=0;j<num;j++)
			{
				profit[j]=a;
				fscanf(fp,"%d",&a);
				indexof[j]=j;
			}
			for(j=0;j<num;j++)
			{
				weight[j]=a;
                                fscanf(fp,"%d",&a);
                        }
		}
		i++;
	}
	printf("%d\n",num);
	printf("%f\n",capacity);
	for(i=0;i<num;i++)
	{
		printf("%d\t",profit[i]);
	}
	printf("\n");
	for(i=0;i<num;i++)
	{
                printf("%d\t",weight[i]);
        }
	for(i=0;i<num;i++)
	{
		ratio[i]=(float)profit[i]/(float)weight[i];
	}
	printf("\n");
	sort();
}
void sort()
{
	int i,j;
	float temp;
	for(i=0;i<num;i++)
	{
		for(j=i+1;j<num;j++)
		{
			if(ratio[i]<ratio[j])
			{
				temp=ratio[j];//swap ratio i and j
				ratio[j]=ratio[i];
				ratio[i]=temp;
				temp=weight[j];//swap weight i and j
				weight[j]=weight[i];
				weight[i]=temp;
				temp=profit[j];//swap profit i and j
				profit[j]=profit[i];
				profit[i]=temp;
				temp=indexof[j];//swap index i and j
				indexof[j]=indexof[i];
				indexof[i]=temp;
			}
		}
	}
	printf("\nSorted Array:\n");
	for(i=0;i<num;i++)
	{
		printf("%0.3f ",ratio[i]);
	}
	knapsack();
}
void knapsack()
{
	float *x=(float *)malloc(num*sizeof(float));
	float tp=0,u;
	int i,j;
	u=capacity;
	for(i=0;i<num;i++)
	{
		x[i]=0.0;
	}
	for(i=0;i<num;i++)
	{
		if(weight[i]>u)
			break;
		else
		{
			x[i]=1.0;
			tp=tp+profit[i];
			u=u-weight[i];
		}
	}
	if(i<num)
		x[i]=u/weight[i];
	tp=tp+(x[i]*profit[i]);
	printf("\nResult vector is: \n");
	for(i=0;i<num;i++)
	{
		printf("For %d : %0.3f \n",indexof[i]+1,x[i]);
	}
	printf("\nMaximum profit is: %0.3f\n",tp);
}	
