#include "5_10.h"
#include <iostream>
#include <vector>
#include <cmath>

void guassian_elimination(double **A, double *b, double *u, int n) {
    for (int k = 0; k < n-1; k++) {
        // Partial pivoting
        int p = k;
        double max = fabs(A[k][k]);
        for (int i = k+1; i < n; i++) {
            if (fabs(A[i][k]) > max) {
                max = fabs(A[i][k]);
                p = i;
            }
        }
        if (p != k) {
            std::swap(A[k], A[p]);
            std::swap(b[k], b[p]);
        }
        // Elimination
        for (int i = k+1; i < n; i++) {
            double factor = A[i][k]/A[k][k];
            for (int j = k+1; j < n; j++) {
                A[i][j] -= factor*A[k][j];
            }
            b[i] -= factor*b[k];
            A[i][k] = 0.0;
        }
    }
    // Back substitution
    for (int i = n-1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i+1; j < n; j++) {
            sum += A[i][j]*u[j];
        }
        u[i] = (b[i]-sum)/A[i][i];
    }
}
