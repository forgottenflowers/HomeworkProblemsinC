// This is valid in C99 or later 
//You can try it here 

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

euler(6,2,4);
return 0;

}	
