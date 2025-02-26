#include "5_6.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iostream>
#include <cassert>


using namespace std;

void Multiply(double** res, double** A, double** B, int ARows, int ACols, int BRows, int BCols) {
    assert(ACols == BRows);
    for (int i = 0; i < ARows; i++) {
        for (int j = 0; j < BCols; j++) {
            res[i][j] = 0;
            for (int k = 0; k < ACols; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// function to vector and matrix


void Multiply(double* res, double* A, double** B, int ACols, int BRows, int BCols) {
    for (int i = 0; i < BRows; i++) {
        res[i] = 0;
        for (int j = 0; j < ACols; j++) {
            res[i] += A[j] * B[j][i];
        }
    }
}



//a matrix and a vector of given sizes;
void Multiply(double* res, double** A, double* B, int ARows, int ACols, int BRows) {
    for (int i = 0; i < ARows; i++) {
        res[i] = 0;
        for (int j = 0; j < ACols; j++) {
            res[i] += A[i][j] * B[j];
        }
    }
}

// multipy a scalar and a matrix of a given size;
void Multiply(double **res, double scalar, double **B, int BRows, int BCols) {
    for (int i = 0; i < BRows; i++) {
        for (int j = 0; j < BCols; j++) {
            res[i][j] = scalar * B[i][j];
        }
    }
}


//a matrix of a given size and a scalar.
void Multiply(double **res, double **B, double scalar, int BRows, int BCols) {
    for (int i = 0; i < BRows; i++) {
        for (int j = 0; j < BCols; j++) {
            res[i][j] = B[i][j] * scalar;
        }
    }
}




//int main(){

//}


/*
//main 1
int main() {
    const int ARows = 2, ACols = 3, BRows = 3, BCols = 4;
    double** A = new double*[ARows];
    double** B = new double*[BRows];
    double** res = new double*[ARows];
     
    cout << "A:"<< endl;
    for (int i = 0; i < ARows; i++) {
        A[i] = new double[ACols];
        res[i] = new double[BCols];
        for (int j = 0; j < ACols; j++) {
            A[i][j] = i * ACols + j;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "B:"<< endl;
    for (int i = 0; i < BRows; i++) {
        B[i] = new double[BCols];
        for (int j = 0; j < BCols; j++) {
            B[i][j] = i * BCols + j;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    Multiply(res, A, B, ARows, ACols, BRows, BCols);

    for (int i = 0; i < ARows; i++) {
        for (int j = 0; j < BCols; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    // Free the memory
    for (int i = 0; i < ARows; i++) {
        delete[] A[i];
        delete[] res[i];
    }
    for (int i = 0; i < BRows; i++) {
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
    delete[] res;

    return 0;
}

*/

//1. test vector and matrix

/*
int main() {
    double* A = new double[3];
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;

    double** B = new double*[3];
    for (int i = 0; i < 3; i++) {
        B[i] = new double[2];
    }
    B[0][0] = 4;
    B[0][1] = 5;
    B[1][0] = 6;
    B[1][1] = 7;
    B[2][0] = 8;
    B[2][1] = 9;

    double* res = new double[2];
    Multiply(res, A, B, 3, 3, 2);

    for (int i = 0; i < 2; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    delete[] A;
    for (int i = 0; i < 3; i++) {
        delete[] B[i];
    }
    delete[] B;
    delete[] res;

    return 0;
}

*/


/*
// text  multipy a scalar and a matrix of a given size;
int main() {

     // Create input matrix B and scalar value
    double** B = new double*[2];
    for (int i = 0; i < 2; i++) {
        B[i] = new double[2];
    }
    B[0][0] = 1; B[0][1] = 2;
    B[1][0] = 3; B[1][1] = 4;
    double scalar = 2;

    // Create result matrix res
    double** res = new double*[2];
    for (int i = 0; i < 2; i++) {
        res[i] = new double[2];
    }

    // Call the Multiply function and print the result
    Multiply(res, scalar, B, 2, 2);
    std::cout << "Result matrix:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory
    for (int i = 0; i < 2; i++) {
        delete[] B[i];
        delete[] res[i];
    }
    delete[] B;
    delete[] res;

    return 0;
    
}
*/

/*

// test a matrix of a given size and a scalar.
int main() {
    int rows = 3;
    int cols = 3;

    // create matrix A
    double **A = new double *[rows];
    for (int i = 0; i < rows; i++) {
        A[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            A[i][j] = i + j;
        }
    }

    // create matrix B
    double **B = new double *[rows];
    for (int i = 0; i < rows; i++) {
        B[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            B[i][j] = i * j;
        }
    }

    // create result matrix C
    double **C = new double *[rows];
    for (int i = 0; i < rows; i++) {
        C[i] = new double[cols];
    }

    // test the Multiply function
    Multiply(C, B, 2.5, rows, cols);

    // print the matrices
    cout << "Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix B:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix C = B * 2.5:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // free memory
    for (int i = 0; i < rows; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}

*/

