#include "5_9.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

void solve3by3(double **A, double *b, double *u) {
    double detA = A[0][0] * (A[1][1]*A[2][2] - A[2][1]*A[1][2])
                - A[0][1] * (A[1][0]*A[2][2] - A[2][0]*A[1][2])
                + A[0][2] * (A[1][0]*A[2][1] - A[2][0]*A[1][1]);
    cout << detA << endl;
    
    double invA[3][3] = {
        {(A[1][1]*A[2][2] - A[2][1]*A[1][2])/detA, -(A[0][1]*A[2][2] - A[2][1]*A[0][2])/detA,  (A[0][1]*A[1][2] - A[1][1]*A[0][2])/detA},
        {-(A[1][0]*A[2][2] - A[2][0]*A[1][2])/detA,  (A[0][0]*A[2][2] - A[2][0]*A[0][2])/detA, -(A[0][0]*A[1][2] - A[1][0]*A[0][2])/detA},
        {(A[1][0]*A[2][1] - A[2][0]*A[1][1])/detA, -(A[0][0]*A[2][1] - A[2][0]*A[0][1])/detA,  (A[0][0]*A[1][1] - A[1][0]*A[0][1])/detA}
    };

    for (int i = 0; i < 3; i++) {
        u[i] = invA[i][0]*b[0] + invA[i][1]*b[1] + invA[i][2]*b[2];



    }
}

/*
int main() {
    double** A = new double*[3];
    for(int i=0; i<3; i++){
        A[i] = new double[3];
    }
    A[0][0]= 1; A[0][1]= 2; A[0][2]=-2;
    A[1][0]= 2; A[1][1]= 1; A[1][2]=-5;
    A[2][0]= 1; A[2][1]= -4; A[2][2]=1;


 //   double b[3] = {1, 2, 3};
    double *b = new double[3];
    b[0]=-15; b[1]=-21; b[2]=18; 

    double *u = new double[3];
    solve3by3(A, b, u);
    cout << "Solution: (" << u[0] << ", " << u[1] << ", " << u[2] << ")" << endl;
    return 0;
}

*/
