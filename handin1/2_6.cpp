
#include "2_6.h"
#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return exp(x) + pow(x, 3.0) - 5.0;
}

double f_prime(double x) {
    return exp(x) + 3.0 * pow(x, 2.0);
}

double newton_Raphson(double initialGuess , double epsilon){
double x_previous;
double x_next;
x_previous = initialGuess;
x_next = x_previous;

for (int i = 0; i<100; i++){
    x_next = x_previous - f(x_previous) / f_prime(x_previous);
    if (abs(x_next - x_previous) < epsilon){
    	break;
    }
    else{
    	x_previous = x_next;
    }
} 
 return x_next;   

}

/*
int main() {
    double init = 0.0;  // initial guess
    double epsilon = 1e-6; 
    double output;
    output = newton_Raphson(init, epsilon);
    cout << "Converged to root x = " << output << endl;

}
*/

/*
int main() {
    double init = 0.0;  // initial guess
    double epsilon = 1e-6; 
    double output;
    output = newton_Raphson(init, epsilon);
    cout << "Converged to root x = " << output << endl;

}
*/
