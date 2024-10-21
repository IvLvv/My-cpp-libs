#include "matrix.h"
#include <iostream>
#include <cassert>

void testAddMatrices() {
    Matrix matrix1({{1.0, 2.0}, {3.0, 4.0}});
    Matrix matrix2({{5.0, 6.0}, {7.0, 8.0}});
    Matrix result = matrix1.add(matrix2);

    assert(result(1, 1) == 6.0);
    assert(result(1, 2) == 8.0);
    assert(result(2, 1) == 10.0);
    assert(result(2, 2) == 12.0);

    std::cout << "testAddMatrices passed!" << std::endl;
}

void testMultiplyMatrices() {
    Matrix matrix1({{1.0, 2.0}, {3.0, 4.0}});
    Matrix matrix2({{5.0, 6.0}, {7.0, 8.0}});
    Matrix result = matrix1.multiply(matrix2);

    assert(result(1, 1) == 19.0);
    assert(result(1, 2) == 22.0);
    assert(result(2, 1) == 43.0);
    assert(result(2, 2) == 50.0);

    std::cout << "testMultiplyMatrices passed!" << std::endl;
}

void testTransposeMatrix() {
    Matrix matrix({{1.0, 2.0}, {3.0, 4.0}});
    Matrix result = matrix.transpose();

    assert(result(1, 1) == 1.0);
    assert(result(1, 2) == 3.0);
    assert(result(2, 1) == 2.0);
    assert(result(2, 2) == 4.0);

    std::cout << "testTransposeMatrix passed!" << std::endl;
}

void testDeterminant() {
    Matrix matrix({{1.0, 2.0}, {3.0, 4.0}});
    double det = matrix.determinant();

    assert(det == -2.0);

    std::cout << "testDeterminant passed!" << std::endl;
}

void testInverseMatrix() {
    Matrix matrix({{4.0, 7.0}, {2.0, 6.0}});
    Matrix result = matrix.inverse();

    assert(result(1, 1) == 0.6);
    assert(result(1, 2) == -0.7);
    assert(result(2, 1) == -0.2);
    assert(result(2, 2) == 0.4);

    std::cout << "testInverseMatrix passed!" << std::endl;
}

int main() {
    testAddMatrices();
    testMultiplyMatrices();
    testTransposeMatrix();
    testDeterminant();
    testInverseMatrix();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}