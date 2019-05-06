#include<stdio.h>
#include<math.h>

void main()
{
    int n,i,j;
    float x;
    printf("enter the no of values\n");
    scanf("%d",&n);
	float a[n][n+1];
    printf("enter the point to be interpolated\n");
    scanf("%f",&x);
    printf("enter the datapoints in the form (x,f(x))\n");
    for(i=0;i<n;i++)
        scanf("%f %f",&a[i][0],&a[i][1]);
    for(j=2;j<n+1;j++)
        for(i=j-1;i<n;i++)
            a[i][j]=a[i][j-1]-a[i-1][j-1];
    printf("\nthe matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
            printf("%0.3lf\t",a[i][j]);
        printf("\n");
    }

	float p = (x - a[n-1][0])/(a[1][0]-a[0][0]);
	float yp=a[n-1][1];
	float k=1;
	for(j=2;j<=n;j++)
	{
		k=k*(p+j-2)/(j-1);
		yp+=k*a[n-1][j];
	}
	printf("Final ans f(%f) is %f\n",x,yp);
}
