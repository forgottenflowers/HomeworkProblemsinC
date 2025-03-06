// This program solves for the function values of the differential equation (dy/dt)=Ay
// You want to approximate the value of y at a given t, for a given A and arbitrary step-size h.
// Edit the value of parameters in main()

// NOTE: This code runs on C99 or later 
// You can try it here: https://onecompiler.com/cpp/43b2msksf


#include <stdio.h>
#include <math.h>

void euler(float A,float h,float t)

{
	float f=exp(A*t);


	float y=1.0;
	
	

	for(int i=0;(i+h)<=t;i+=h)

		y*=1+(h*A);

		


	printf("The solution is: %f\n",y);


	float error=y-f;

	printf("The error is: %f\n",error);


	float eperc=(error/f)*100;

	printf("The percentage error is: %f\n",eperc);

}




main()
{

euler(6,2,4); //Edit these values
return 0;

}	
