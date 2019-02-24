#include<stdio.h>
#include<math.h>
void main()
{
    int n,i,j;
    float x,a[10][10];
    printf("enter the no of values\n");
    scanf("%d",&n);
    printf("enter the point to be interpolated\n");
    scanf("%f",&x);
    printf("enter the datapoints\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i][0]);
    }
    printf("enter the values of the datapoints\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i][1]);
    }
    for(j=2;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            a[i][j]=a[i+1][j-1]-a[i][j-1];
        }
    }
    printf("\nthe matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1+i;j++)
        {
            printf("%f\t",&a[i][j]);
        }
        printf("\n");
    }
}
