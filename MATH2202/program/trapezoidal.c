#include<stdio.h>
#include<math.h>
#define f(x) (pow(2.71,x)/(1+(pow(x,4))))
void main()
{
    int n,i;
    printf("enter the value of n");
    scanf("%d",&n);
    float a,b,h,y0,yn,temp=0.0,sum,x[n+1],y[n+1];
    printf("enter the lower limit");
    scanf("%f",&a);
    printf("enter the upper limit");
    scanf("%f",&b);
    h=(b-a)/n;
    for(i=0;i<n+1;i++)
    {
        x[i]=a+i*h;
        y[i]=f(x[i]);

    }
    sum=y[0]+y[n];
    for(i=1;i<n;i++)
    {
        temp=temp+y[i];
    }
    temp=temp*2;
    sum=sum+temp;
    sum=(sum*h)/2;
    printf("the value is %f",sum);
}
