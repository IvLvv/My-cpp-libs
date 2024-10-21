#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>
#include <iostream>

class Matrix {
public:
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<int>>& values);

    // Функция для сложения двух матриц
    Matrix add(const Matrix& other) const;

    // Функция для умножения двух матриц
    Matrix multiply(const Matrix& other) const;

    // Функция для транспонирования матрицы
    Matrix transpose() const;

    // Функция для вывода матрицы
    void print() const;

    // Геттеры для получения количества строк и столбцов
    int getRows() const;
    int getCols() const;

    // Перегрузка оператора для доступа к элементам матрицы
    int& operator()(int row, int col);
    const int& operator()(int row, int col) const;

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> values;
};

// Определения функций

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), values(rows, std::vector<int>(cols, 0)) {}

Matrix::Matrix(const std::vector<std::vector<int>>& values) : rows(values.size()), cols(values[0].size()), values(values) {}

Matrix Matrix::add(const Matrix& other) const {
    int maxRows = std::max(rows, other.rows);
    int maxCols = std::max(cols, other.cols);

    Matrix result(maxRows, maxCols);

    for (int i = 0; i < maxRows; ++i) {
        for (int j = 0; j < maxCols; ++j) {
            int val1 = (i < rows && j < cols) ? values[i][j] : 0;
            int val2 = (i < other.rows && j < other.cols) ? other.values[i][j] : 0;
            result.values[i][j] = val1 + val2;
        }
    }

    return result;
}

Matrix Matrix::multiply(const Matrix& other) const {
    int maxRows = std::max(rows, other.rows);
    int maxCols = std::max(cols, other.cols);

    Matrix result(maxRows, maxCols);

    for (int i = 0; i < maxRows; ++i) {
        for (int j = 0; j < maxCols; ++j) {
            int sum = 0;
            for (int k = 0; k < std::min(cols, other.rows); ++k) {
                int val1 = (i < rows && k < cols) ? values[i][k] : 0;
                int val2 = (k < other.rows && j < other.cols) ? other.values[k][j] : 0;
                sum += val1 * val2;
            }
            result.values[i][j] = sum;
        }
    }

    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.values[j][i] = values[i][j];
        }
    }
    return result;
}

void Matrix::print() const {
    for (const auto& row : values) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

int& Matrix::operator()(int row, int col) {
    if (row < 1 || row > rows || col < 1 || col > cols) {
        throw std::out_of_range("Index out of range");
    }
    return values[row - 1][col - 1];
}

const int& Matrix::operator()(int row, int col) const {
    if (row < 1 || row > rows || col < 1 || col > cols) {
        throw std::out_of_range("Index out of range");
    }
    return values[row - 1][col - 1];
}

#endif // MATRIX_H