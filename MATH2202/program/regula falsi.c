#include<stdio.h>
#include<math.h>
#define f(x) ((pow(x,3)*tan(x))+pow(x,2)-(2*x)-5)
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
    newx=b;
    do
    {
        c++;
        oldx=(a*f(b)-b*f(a))/(f(b)-f(a));
        if(f(a)*f(oldx)<0)
            b=oldx;
        else
            a=oldx;
        newx=(a*f(b)-b*f(a))/(f(b)-f(a));
    }while(fabs(newx-oldx)>t);
    printf("root in iteration no. %d is %f",c ,newx);
}
