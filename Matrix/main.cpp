#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
    // Пример использования класса Matrix
    vector<vector<int>> values1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> values2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix matrix1(values1);
    Matrix matrix2(values2);

    // Вывод первой матрицы
    cout << "Matrix 1:" << endl;
    matrix1.print();

    // Вывод второй матрицы
    cout << "Matrix 2:" << endl;
    matrix2.print();

    try {
        // Сложение матриц
        Matrix sum = matrix1.add(matrix2);
        cout << "Sum of Matrix 1 and Matrix 2:" << endl;
        sum.print();

        // Умножение матриц
        Matrix product = matrix1.multiply(matrix2);
        cout << "Product of Matrix 1 and Matrix 2:" << endl;
        product.print();

        // Транспонирование первой матрицы
        Matrix transposed = matrix1.transpose();
        cout << "Transpose of Matrix 1:" << endl;
        transposed.print();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}