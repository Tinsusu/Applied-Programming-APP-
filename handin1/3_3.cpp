#include "3_3.h"
// #include <iostream>
// #include <cmath>
#include <fstream>

using namespace std;
void implicit_Euler(int n){
	// Calculate the step size h
    double h = 1.0 / (n - 1.0);

    // Initialize x and y
    double x = 0.0;
    double y = 1.0;

    // Open a file to write the data
    ofstream outfile("xy.dat");

    if(outfile.is_open()){
    	for(int i =0; i < n; i++){
    		outfile << x << ","<< y << endl;
    		x = x + h;
    		y = y - y*h;
    	}
    	outfile.close();
    }
}

/*
int main(int argc, char* argv[]) {
// Check the number of command line arguments
    int n = atoi(argv[1]);
    // Check that the number of grid points is greater than 1
    assert(n > 1);
    implicit_Euler(n);
}

*/
// clang++ -Wall -std=c++14 3_3.cpp -o 3_3test
// ./3_3test


