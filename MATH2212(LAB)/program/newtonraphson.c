#include<stdio.h>
#include<math.h>
#define f(x) (2*pow(x,3)-(2.5*x)-5)
#define df(x) ((6*x*x)-2.5)
void main()
{
    float a,b,t,oldx,newx;
    int c=0;
    a=0.0,b=1.0,t=0.00001;
    while(f(a)*f(b)>0)
    {
        a++;
        b++;
    }
	newx=a;
    do
    {
		a=newx;
        c++;
        newx=a-(f(a)/df(a));
    }while(fabs(f(newx)-f(a))>t);
    printf("root in iteration no. %d is %0.9f",c ,newx);
}
