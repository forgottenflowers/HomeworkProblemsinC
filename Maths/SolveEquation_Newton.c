// This function applies Newton's Method to find a root of f(y), starting at an initial guess x.

#include<stdio.h>
#include<math.h>

double f(double y)
{
  double ans=y*y*y-3*y+1;
  return ans;
}

double diff(double f(double y),double x)
{
  double e,x1,x0,fx,fx1,fx0,diffr,diffl,result;
  
  e=0.00000000000001;
  // To increase accuracy, e should be small. But an extremely small e (10⁻¹⁴) could possibly lead to floating-point precision errors.
  // You may use 10^(⁻7) instead. It's more stable.
  
  x1=x+e;
  x0=x-e;
  fx=f(x);
  fx1=f(x1);
  fx0=f(x0);
  
  diffr=(fx1-fx)/e;    // Forward difference derivative
  diffl=(fx-fx0)/e;    // Backward difference derivative
  result=(diffr+diffl)/2;
  return result;
}

void newton(double f(double y), double x)
{
  double fx,di;
  int q;
  for(q=0;q<1000;q++)    // iterate 1000 times
    {
      fx=f(x);
      di=diff(f,x);
      if(fx==0)break;      // exit if we found a solution
      else x=x-(fx/di);    // otherwise, x is updated using the Newton-Raphson formula
    }
  printf ("%f\n",x);
}

main()
{
  newton(f,0.53);
  return 0;
}

// Suggestions:
// Can use a convergence check like fabs(fx) < 1e-7 instead of limited number of iterations.
// It is very unlikely that a division by 0 would occur here unless the user enters this on purpose. To prevent crash, you can check if (fabs(di) < 1e-10) break; 
