#include "matrix.h"
#include <iostream>

using namespace std;

int main() {
    // Пример использования класса Matrix
    vector<vector<double>> values1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<double>> values2 = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    Matrix matrix1(values1);
    Matrix matrix2(values2);

    // Пример доступа к элементам матрицы в матричном стиле
    cout << "Element at (2, 2) in Matrix 1: " << matrix1(2, 2) << endl;

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

        // Нахождение определителя первой матрицы
        cout << "Determinant of Matrix 1: " << matrix1.determinant() << endl;

        // Нахождение обратной матрицы для первой матрицы
        Matrix inverse = matrix1.inverse();
        cout << "Inverse of Matrix 1:" << endl;
        inverse.print();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}