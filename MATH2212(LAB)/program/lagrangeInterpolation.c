#include<stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	printf("Enter n :");
	scanf("%d",&n);
	double x[n];
	double fx[n];
	int i,j;
	double x0;
	double ans=0.0;
	for(i=0;i<n;i++)
	{
		printf("Enter %dth (x,f(x)) :",i+1);
		scanf("%lf%lf",&x[i],&fx[i]);
	}
	printf("Enter the interpolating point x0 : ");
	scanf("%lf",&x0);
	for(i=0;i<n;i++)
	{
		double a=fx[i];
		for(j=0;j<n;j++)
			if(j!=i)
				a=a*((double)(x0-x[j])/(x[i]-x[j]));
		ans=ans+a;
	}
	printf("Answer is %lf\n",ans);
}
