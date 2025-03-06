// This program computes the inverse of a matrix using LU decomposition (specifically Doolittle's method).
// This is used to solve a system of linear equations.
// Notes: 
// The Doolittle Algorithm is a method for performing LU Decomposition, where a given matrix is decomposed into a lower triangular matrix L and an upper triangular matrix U. 
// This decomposition is widely used in solving systems of linear equations, inverting matrices, and computing determinants.
// More info here: https://www.geeksforgeeks.org/doolittle-algorithm-lu-decomposition/

#include <stdio.h>

int main() {
    int n, i, j, t, q, z;
    float temp;
    
    // Taking user input for matrix size
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    
    // Declare matrices
    float a[n][n], u[n][n], l[n][n], inv[n][n], idm[n][n], b[n], c[n], x[n];
    
    // Initialize matrices
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j == i) {
                l[i][j] = 1.0;
                idm[i][j] = 1.0;  // Identity matrix
            } else {
                l[i][j] = 0.0;
                idm[i][j] = 0.0;
            }
            u[i][j] = 0.0;
            inv[i][j] = 0.0;
        }
    }
    
    // Input matrix elements
    printf("Enter the elements of the matrix whose inverse you want to find:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("a%d%d: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    // LU Decomposition: L * U = A
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            temp = 0.0;
            for(t = 0; t < i; t++) {
                temp += l[i][t] * u[t][j];
            }
            u[i][j] = (a[i][j] - temp) / l[i][i];
        }
        
        for(j = i + 1; j < n; j++) {
            temp = 0.0;
            for(t = 0; t < i; t++) {
                temp += l[j][t] * u[t][i];
            }
            l[j][i] = (a[j][i] - temp) / u[i][i];
        }
    }
    
    // Solve for the inverse: L * C = I and U * X = C
    for(q = 0; q < n; q++) {
        for(z = 0; z < n; z++) {
            b[z] = idm[z][q];
        }

        // Forward substitution: L * C = I
        for(i = 0; i < n; i++) {
            temp = 0.0;
            for(j = 0; j < n; j++) {
                temp += l[i][j] * c[j];
            }
            c[i] = b[i] - temp;
        }

        // Backward substitution: U * X = C
        for(i = n - 1; i >= 0; i--) {
            temp = 0.0;
            for(j = i + 1; j < n; j++) {
                temp += u[i][j] * x[j];
            }
            x[i] = (c[i] - temp) / u[i][i];
        }

        // Fill the inverse matrix
        for(z = 0; z < n; z++) {
            inv[z][q] = x[z];
        }
    }

    // Print the inverse matrix
    printf("Inverse matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%f ", inv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
