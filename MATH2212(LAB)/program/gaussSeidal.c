/*
#include<stdio.h>
#include<math.h>
void main()
{
    int n;
    printf("enter the number of equations\n");
    scanf("%d",&n);
    float a[n],b[n],c[n],d[n];
    int i;
    float t=0.00001; 

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
    while((fabs(x-x1) < t) &&)
    {
        x=(d[0]-(b[0]*y1)-(c[0]*z1))/a[0];
        //t=fabs(x-x1);
        x1=x;
        y=(d[1]-(a[1]*x1)-(c[1]*z1))/b[1];
        y1=y;
        z=(d[2]-(a[2]*x1)-(b[2]*y1))/c[2];
        z1=z;
    }
    printf("x = %f\ny =  %f\nz = %f\n",x,y,z);

}

















#include<stdio.h> 
#include<math.h> 
void main() 
{
 f l oata[ 10] [ 10] , x[ 20] , sum, t emp[ 10] , t ;
 i nti , j , k, n, f ;
 pr i nt f ( " \ n\ tent ert heor deroft hemat r i x: " ) ; 
scanf ( " %d" , &n) ; pr i nt f ( " \ n\ tent ert het ol er ancel i mi t : " ) ; scanf ( " %f " , &t ) ; pr i nt f ( " \ n\ tent ert heel ementoft hemat r i x\ n\ t " ) ; f or ( i =1; i <=n; i ++) { f or ( j =1; j <=n+1; j ++) scanf ( " %f " , &a[ i ] [ j ] ) ; pr i nt f ( " \ n\ t " ) ; } f or ( i =1; i <=n; i ++) x[ i ] =0; f =1; whi l e( f ) { f or ( i =1; i <=n; i ++) { sum=0; t emp[ i ] =x[ i ] ; f or ( j =1; j <=n; j ++) { i f ( j ! =i ) sum+=a[ i ] [ j ] * x[ j ] ; } x[ i ] =( a[ i ] [ n+1] - sum) / a[ i ] [ i ] ; } f =0; f or ( i =1; i <=n; i ++) { i f ( f abs( x[ i ] - t emp[ i ] ) >t ) f =1; } } f or ( i =1; i <=n; i ++) pr i nt f ( " x[ %d] =%f \ n" , i , x[ i ] ) ; get ch( ) ;



*/
#include<stdio.h>
#include<math.h>
#define e 0.00001
void main()
{
 int i,j,k,n;
    float a[10][10],x[10];
    float sum,temp,error,big; 
    printf("Enter the number of equations: ");
    scanf("%d",&n) ;
    printf("Enter the co-efficients of the equations: \n");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n+1;j++)
 {
 printf("a[%d][%d]= ",i,j);
 scanf("%f",&a[i][j]);
 }
 }
 for(i=1;i<=n;i++)
 {
 x[i]=0;
 }
 do
 {
 big=0;
 for(i=1;i<=n;i++)
 {
 sum=0;
 for(j=1;j<=n;j++)
 {
 if(j!=i)
 {
 sum=sum+a[i][j]*x[j];
 }
 }
 temp=(a[i][n+1]-sum)/a[i][i];
 error=fabs(x[i]-temp);
 if(error>big)
 {
 big=error;
 }
 x[i]=temp;
 printf("\nx[%d] =%f",i,x[i]);
 }printf("\n");
 }
 while(big>=e);
 printf("\n\nconverges to solution");
 for(i=1;i<=n;i++)
 {
 printf("\nx[%d]=%f",i,x[i]);
 }
}

