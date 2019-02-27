#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*flag,count=0,value;
	printf("Enter n:");
	scanf("%d",&n);
	flag=(int*)calloc(n+1,sizeof(int));
	FILE* fp;
	fp=fopen("data.txt","w+");
	srand(time(NULL));
	fprintf(fp,"%d\n",n);
	while(1)
	{
		value=rand()%n+1;
		if(!flag[value])
		{
			count++;
			flag[value]=1;
			fprintf(fp,"%d\n",value);
			}
		if(count==n)
		  break;
		}
	fclose(fp);
	return;
	}
