#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

struct Matrix {
    std::vector<std::vector<double>> data;

    Matrix() {}

    Matrix(int rows, int cols) : data(rows, std::vector<double>(cols)) {}

    void load(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            int rows, cols;
            file >> rows >> cols;
            data.resize(rows, std::vector<double>(cols));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    file >> data[i][j];
                }
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file: " << filename << std::endl;
        }
    }

    int n_rows() const {
        return data.size();
    }

    int n_cols() const {
        return data.empty() ? 0 : data[0].size();
    }

    std::vector<double>& operator[](int i) {
        return data[i];
    }

    const std::vector<double>& operator[](int i) const {
        return data[i];
    }
};

struct Vector {
    std::vector<double> data;

    Vector() {}

    Vector(int size) : data(size) {}

    int size() const {
        return data.size();
    }

    double& operator[](int i) {
        return data[i];
    }

    const double& operator[](int i) const {
        return data[i];
    }

    void save(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < data.size(); ++i) {
                file << data[i] << std::endl;
            }
            file.close();
        } else {
            std::cerr << "Error: Unable to open file: " << filename << std::endl;
        }
    }
};

int main() {
    Matrix dataX, dataXTest;
    Vector dataY;
    dataX.load("./data/dataX.dat");
    dataXTest.load("./data/dataXtest.dat");
    dataY.load("./data/dataY.dat");

    // iterating through each point
    int trainDims = dataX.n_cols();
    int trainRows = dataX.n_rows();
    int testRows = dataXTest.n_rows();
    Vector dataYTest(testRows);

    const double epsilon = 1.0e-7;
    const double alpha = 0.5;

    // learning process
    Vector weight(trainDims), dL_dw(trainDims);
    while (true) {
        for (int i = 0; i < trainRows; ++i) {
            double inner = 0.0;
            for (int j = 0; j < trainDims; ++j) {
                inner += weight[j] * dataX[i][j];
            }
            double factor = 1.0 / (1 + exp(-dataY[i] * inner));
            for (int j = 0; j < trainDims; ++j) {
                dL_dw[j] += dataY[i] * factor * dataX[i][j];
            }
        }
        for (int j = 0; j < trainDims; ++j) {
            dL_dw[j] = -dL_dw[j] / trainRows;
            weight[j] -= alpha * dL_dw[j];
        }
        double norm = 0.0;
        for (int j = 0; j < trainDims; ++j) {
            norm += dL_dw[j] * dL_dw[j];
        }
        norm = sqrt(norm);
        if (norm < epsilon) {
            break;
        }
    }

    // predicting process
    for (int i = 0; i < testRows; ++i) {
        double pred = 0.0;
        for (int j = 0; j < trainDims; ++j) {
            pred += weight[j] * dataXTest[i][j];
        }
        dataYTest[i] = pred < 0 ? -1 : 1;
    }

    dataYTest.save("./LogReg.dat");

    return 0;
}
