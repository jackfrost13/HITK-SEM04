#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 0.001
float dydx(float x, float y) 
{ 
    return ((float)((y*y)-(x*x))/(float)((y*y)+(x*x))); 
} 
int main()
{
	double x0,y0,h,xf,i,yi;
	printf("Enter x0 and y0 :");
	scanf("%lf%lf",&x0,&y0);
	printf("Enter the final value of x :");
	scanf("%lf",&xf);
	h=(float)(xf-x0)/100.0;
	int n = (int)((xf - x0) / h); 
	for(i=0;i<n;i++)
	{
		y0=y0+h*dydx(x0,y0);
		printf("y(%lf) =%lf\n",x0,y0);
		x0=x0+h;
	}
}	
