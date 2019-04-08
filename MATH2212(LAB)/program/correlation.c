#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i,n;
	float x[100],y[100],sumy=0,sumx=0,meanx,meany,cov=0,sdx=0,sdy=0,b,r;
	printf("Enter the number of datas :");
	scanf("%d",&n);
	printf("Enter the x values\n");
	for(i=1;i<=n;i++)
	{
		scanf("%f",&x[i]);
		sumx=sumx+x[i];
	}
	meanx=sumx/n;
	printf("Enter the y values\n");
	for(i=1;i<=n;i++)
	{
		scanf("%f",&y[i]);
		sumy=sumy+y[i];
	}
	meany=sumy/n;
	for(i=1;i<=n;i++)
	{
		cov=cov+(x[i]-meanx)*(y[i]-meany);
		sdx=sdx+pow((x[i]-meanx),2);
		sdy=sdy+pow((y[i]-meany),2);
	}
	sdx=sqrt(sdx/n);
	sdy=sqrt(sdy/n);
	printf("sdx=%f  sdy=%f\n",sdx,sdy);
	cov=cov/n;
	r=cov/(sdx*sdy);
	b=cov/pow(sdx,2);
	printf("Correlation Coefficient is = %f\n",r);
	printf("Regressionline is (y-%f) =%f (x-%f)\n",meany,b,meanx);
}
