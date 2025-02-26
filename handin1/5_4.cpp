#include "5_4.h"
// #include <iostream>
#include <cmath>
// #include <fstream>

// using namespace std;

double calc_mean(double a[], int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += a[i];
    }
    return sum / length;
}

double calc_std(double a[], int length) {
    double mean = calc_mean(a, length);
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += pow(a[i] - mean, 2);
    }
    if (length > 1) {
        return sqrt(sum / (length - 1));
    } else {
        return 0;
    }
}


/*
int main() {
    double arr[] = {1.2, 2.3, 3.4, 4.5, 5.6};
    int length = sizeof(arr) / sizeof(arr[0]);
    double mean = calc_mean(arr, length);
    double std_dev = calc_std(arr, length);
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Standard deviation: " << std_dev << std::endl;
    return 0;
}
*/

