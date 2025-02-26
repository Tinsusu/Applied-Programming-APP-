#include "5_3.h"
// #include <iostream>
// #include <cmath>
// #include <fstream>

// using namespace std;

void swap_pointer(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}


void swap_ref(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

/*
int main(){
double x = 3.14, y = 2.71;
cout << "x =" << x << "y:"<< y << endl;
swap_pointer(&x, &y);
cout << "x =" << x << "y:"<< y << endl;

double a = 10, b = 20;
cout << "a =" << a << "b:"<< b << endl;
swap_ref(a,b);
cout << "a =" << a << "b:"<< b << endl;

}
*/