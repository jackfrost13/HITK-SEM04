#include<stdio.h>
#include<stdlib.h>
long power(int,int);
int count=0;
int main()
{	int x,y;
	long pow;
	printf("Enter value of x\n");
	scanf("%d",&x);
	printf("Enter power of y\n");
	scanf("%d",&y);
	count=0;
	pow=power(x,y);
	printf("The number of steps is %d\n",count);
	printf("The result is %ld\n",pow);
	return 0;
}
long power(int x,int y)
{	count++;
	if(y==0)
		return 1;
	else if(y==1)
		return x;
	else{
		return x*power(x,y-1);
}
}

