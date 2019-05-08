#include<stdio.h>
float dydx(float x, float y) 
{ 
    return ((float)((y*y)-(x*x))/(float)((y*y)+(x*x))); 
} 
float rungeKutta(float x0, float y0, float x, float h) 
{  
    int n = (int)((x - x0) / h); 
    float k1, k2, k3, k4, k5; 
    float y = y0; 
    for (int i=1; i<=n; i++) 
    { 
        k1 = h*dydx(x0, y); 
        k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1); 
        k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2); 
        k4 = h*dydx(x0 + h, y + k3); 
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
        x0 = x0 + h; 
    } 
    return y; 
} 
int main() 
{ 
	float x0,y0,x,h; 
	printf("Enter X0 and Y0 : ");
	scanf("%f %f",&x0,&y0);
	printf("Enter the value of X : ");
	scanf("%f",&x);
	h=(float)(x-x0)/100.0;
	printf("%f",h);
    printf("\nThe value of y at x is : %f",rungeKutta(x0, y0, x, h)); 
    return 0; 
} 
