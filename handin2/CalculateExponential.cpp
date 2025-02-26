#include "CalculateExponential.hpp"

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){
    // Init res value when nMax = 0 (Identity)
    for(int i=0; i<3; i++){
        res[i][i] = ComplexNumber(1,0); 
    }

    // Assume diagonalizable A
    ComplexNumber sum_matrix[3][3];
    ComplexNumber temp_matrix[3][3];
    temp_matrix[0][0] = ComplexNumber(1,0); 
    temp_matrix[1][1] = ComplexNumber(1,0); 
    temp_matrix[2][2] = ComplexNumber(1,0); 

    for(int n=0; n<nMax; n++){
        double factorial = 1; 
        for(int i=n+1; i>0; i--){
            factorial *= i;
        }

        for(int i=0; i<3; i++){
            temp_matrix[i][i] = temp_matrix[i][i]*A[i][i];
            std::cout<< sum_matrix[i][i] << "\n";
            sum_matrix[i][i] = sum_matrix[i][i] + ComplexNumber(temp_matrix[i][i].GetRealPart()/factorial, temp_matrix[i][i].GetImaginaryPart()/factorial);
            std::cout<< sum_matrix[i][i] << "\n";
        }
    }

    for(int i=0; i<3; i++){
        res[i][i] = res[i][i] + sum_matrix[i][i]; 
    }

    std::cout << "Final result: \n";
    printMatrix(res, 3, 3);
}


//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            std::cout << A[i][j];
            if(j!=cols-1){
                std::cout << " ";
            }else{
                std::cout << "\n";
            }
        }
    }
}