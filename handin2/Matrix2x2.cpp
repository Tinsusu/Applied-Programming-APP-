#include "Matrix2x2.hpp"

//Overriden default constructor
Matrix2x2::Matrix2x2(){
    val00 = 0.0;
    val01 = 0.0;
    val10 = 0.0;
    val11 = 0.0;
}

//Overriden copy constructor
Matrix2x2::Matrix2x2(const Matrix2x2& other){
    val00 = other.val00;
    val01 = other.val01;
    val10 = other.val10;
    val11 = other.val11;
}

//Custom constructor
Matrix2x2::Matrix2x2(double a, double b, double c, double d){
    val00 = a;
    val01 = b;
    val10 = c;
    val11 = d;
}

//Calculating determinant
double Matrix2x2::CalcDeterminant() const{
    return ((val00*val11) - (val01*val10));
}

//Inverse of matrix
Matrix2x2 Matrix2x2::CalcInverse() const{
    double det = CalcDeterminant();
    return Matrix2x2(Getval11()/det, -Getval01()/det, -Getval10()/det, Getval00()/det);
}

//Overloading of assignment 
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z){
    val00 = z.val00;
    val01 = z.val01;
    val10 = z.val10;
    val11 = z.val11;
    return *this;
}

//Overloading unary //
Matrix2x2 Matrix2x2::operator-() const{
    Matrix2x2 w;
    w.val00 = -val00;
    w.val01 = -val01;
    w.val10 = -val10;
    w.val11 = -val11;
    return w;
}

//Overloading addition //
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const{
    Matrix2x2 w;
    w.val00 = val00 + z.val00;
    w.val01 = val01 + z.val01;
    w.val10 = val10 + z.val10;
    w.val11 = val11 + z.val11;
    return w;
}

//Overloading substraction
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const{
    Matrix2x2 w;
    w.val00 = val00 - z.val00;
    w.val01 = val01 - z.val01;
    w.val10 = val10 - z.val10;
    w.val11 = val11 - z.val11;
    return w;
}

//Multiply matrix by a scalar
void Matrix2x2::MultScalar(double scalar){
    val00 = scalar*val00;
    val01 = scalar*val01;
    val10 = scalar*val10;
    val11 = scalar*val11;
    Print();
}

void Matrix2x2::Print() const{
    std::cout << val00 << " " << val01 << "\n" << val10 << " " << val11;
}