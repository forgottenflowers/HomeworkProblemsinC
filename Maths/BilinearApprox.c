#include <stdio.h>
#include <math.h>

// Function implementing numerical integration (Euler or Runge-Kutta variant)
void RK(float A, float h, float t)
{
    float f = exp(A * t);  // Exact solution: e^(A*t)
    float y = 1.0;  // Initial condition (assuming y(0) = 1)
    float w = h / 2;  // Step adjustment factor

    // Iteration for numerical solution
    for (float i = 0; i + h <= t; i += h)
    {
        y *= (1 + w) / (1 - w);
    }

    // Display results
    printf("The numerical solution is: %f\n", y);

    float error = fabs(y - f);  // Absolute error
    printf("The absolute error is: %f\n", error);

    float eperc = (error / f) * 100;  // Percentage error
    printf("The percentage error is: %f%%\n", eperc);
}

int main()
{
    float A = 1.0;  // Example A value
    float h = 0.1;  // Step size
    float t = 2.0;  // Final time

    RK(A, h, t);  // Call function with valid arguments

    return 0;
}
