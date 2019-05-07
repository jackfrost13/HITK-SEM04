#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	printf("Enter the number of unknowns : ");
	scanf("%d",&n);
    float x[n][n+1],a[n],ae=0.001,t,s,e;
    int i,j,r,q=0;
    for(i=0;i<n;i++) 
		a[i]=0;
    printf(" Enter the elements of augmented matrix rowwise\n");
    for(i=0;i<n;i++)
    	for(j=0;j<n+1;j++)
    		scanf("%f",&x[i][j]);
    do
    {
        for(i=0;i<n;i++)
        {
            s=0;
            for(j=0;j<n;j++)
            	if(j!=i) 
					s+=x[i][j]*a[j];
            t=(x[i][n]-s)/x[i][i];
            e=fabs(a[i]-t);
            a[i]=t;
        }
        printf("Iteration Number : %d\n",++q);
        for(i=0;i<n;i++)
    		printf("a[%d]=%0.4f\n",i+1,a[i]);
		printf("\n");
	}while(e>0.000000001);
    printf(" Converses in %d iteration\n", q);
    for(i=0;i<n;i++)
    	printf("a[%d]=%0.4f\n",i+1,a[i]);
    return 0; 
}
