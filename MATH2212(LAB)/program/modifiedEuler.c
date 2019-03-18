#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 0.001
#define f(x,y) ((x)*(y))
int main()
{
	double x,y,h,xf,y1,y2;
	printf("Enter x0 and y0 :");
	scanf("%lf%lf",&x,&y);
	printf("Enter h :");
	scanf("%lf",&h);
	printf("Enter the final value of x :");
	scanf("%lf",&xf);
	do
	{
		y1=y+h*f(x,y);
		do{
			y2=y1;
			y1=y + h/2*(f(x,y)+f(x+h,y2));
			printf("Modified ym(%lf) = %lf\n",x,y1);
		}while(fabs(y2-y1)>0.00001);
		x+=h;
		y=y1;
		printf("\n\n\ny(%lf) =%lf\n",x,y);
	}while(fabs(xf-x)>e);
}	
