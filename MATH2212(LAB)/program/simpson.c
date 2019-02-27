#include<stdio.h>
#include<math.h>
#define f(x) (sin(x)/(1+(pow(x,3))))
void main()
{
    int n,i;
    printf("enter the value of n\t");
    scanf("%d",&n);
    float a,b,h,y0,yn,temp1=0.0,temp2=0.0,sum,x[n+1],y[n+1];
    printf("enter the lower limit\t");
    scanf("%f",&a);
    printf("enter the upper limit\t");
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
        if(i%2==0)
            temp1=temp1+y[i];
        else
            temp2=temp2+y[i];
    }
    temp1=temp1*2;
    temp2=temp2*4;
    sum=sum+temp1+temp2;
    sum=(sum*h)/3;
    printf("the value is %f",sum);
}
