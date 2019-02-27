#include<stdio.h>
#include<time.h>
int count=0;
void towerofhanoi(int n,char s,char d,char aux)
{	count++;
	if(n==1)
	{	printf("\nMove disk 1 from %c to %c",s,d);
		return;
	}
	towerofhanoi(n-1,s,aux,d);
	printf("\nMove disk %d from %c to %c",n,s,d);
	//count++;
	towerofhanoi(n-1,aux,d,s);
}
void main()
{	int n;
	printf("Enter the number of disks\n");
	scanf("%d",&n);	
	towerofhanoi(n,'S','D','A');
	printf("\nThe number of comparisons are %d",count);
}
