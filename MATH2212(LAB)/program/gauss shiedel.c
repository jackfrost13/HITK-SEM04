#include<stdio.h>
#include<math.h>
void main()
{
    int n;
    printf("enter the number of equations\n");
    scanf("%d",&n);
    float a[n],b[n],c[n],d[n];
    int i,t=0;

    for(i=0;i<n;i++)
    {
        printf("enter the co efficient of x polynomial\n");
        scanf("%f",&a[i]);
    printf("enter the coefficient of y polynomial\n");
        scanf("%f",&b[i]);
    printf("enter the coefficient of z polynomial\n");
        scanf("%f",&c[i]);
    printf("enter the value of constant\n");
        scanf("%f",&d[i]);
    }
    float x1=0.0,y1=0.0,z1=0.0,x=0.0,y=0.0,z=0.0;
    while(t<15)
    {
        x=(d[0]-(b[0]*y1)-(c[0]*z1))/a[0];
        //t=fabs(x-x1);
        x1=x;
        y=(d[1]-(a[1]*x1)-(c[1]*z1))/b[1];
        y1=y;
        z=(d[2]-(a[2]*x1)-(b[2]*y1))/c[2];
        z1=z;
        t++;
        ;

    }
    printf("x = %f\ny =  %f\nz = %f\n",x,y,z);

}
