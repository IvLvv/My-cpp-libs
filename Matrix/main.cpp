#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
    // Create two matrices
    Matrix mat1({{1, 2}, {3, 4}});
    Matrix mat2({{5, 6}, {7, 8}});

    // Add matrices
    Matrix result = mat1.add(mat2);
    std::cout << "Sum of matrices:" << std::endl;
    result.print();

    // Multiply matrices
    result = mat1.multiply(mat2);
    std::cout << "Product of matrices:" << std::endl;
    result.print();

    // Transpose matrix
    result = mat1.transpose();
    std::cout << "Transpose of matrix 1:" << std::endl;
    result.print();

    // Calculate determinant
    int det = mat1.determinant();
    std::cout << "Determinant of matrix 1: " << det << std::endl;

    // Find inverse
    result = mat1.inverse();
    std::cout << "Inverse of matrix 1:" << std::endl;
    result.print();

    return 0;
}