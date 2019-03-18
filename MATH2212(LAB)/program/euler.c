#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 0.001
#define f(x,y) ((x)*(y))
int main()
{
	double x0,y0,h,xf,i,yi;
	printf("Enter x0 and y0 :");
	scanf("%lf%lf",&x0,&y0);
	printf("Enter h :");
	scanf("%lf",&h);
	printf("Enter the final value of x :");
	scanf("%lf",&xf);
	for(i=x0;fabs(xf-i) >e;i+=h)
	{
		y0=y0+h*f(i,y0);
		printf("y(%lf) =%lf\n",i,y0);
	}
}	
