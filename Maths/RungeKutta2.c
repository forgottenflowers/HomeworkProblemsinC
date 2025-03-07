// This program approximates the solution of the differential equation dx/dt=f(t,x) using 2nd order Runge-Kutta method (RK2).

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function defining the differential equation dx/dt = f(t, x)
float f(float t, float x)
{
float y;
y=2+(x-t-1)*(x-t-1);
return y;
}

// Runge-Kutta 2nd order method
main()
{
float a,b,k1,k2,h,t,x,c,g;
int n,i;

n=72;            // Number of iterations
a=1.0;           // Initial t
b=1.5625;        // Final t
c=2.0;           // Initial x
h=(b-a)/n;       // Step size

t=a;
x=c;
g=t;
for(i=1;i<=n;i++)
{

k1=f(t,x);
k2=f(t+h, x+k1*h);
x=x+(1.0/2.0)*h*(k1+k2);
t=t+h;
printf("\n Integral is %f \n", x);
}


}
