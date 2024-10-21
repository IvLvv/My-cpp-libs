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
    std::vector<int>& operator[](int row);
    const std::vector<int>& operator[](int row) const;

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> values;
};

// Определения функций

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), values(rows, std::vector<int>(cols, 0)) {}

Matrix::Matrix(const std::vector<std::vector<int>>& values) : rows(values.size()), cols(values[0].size()), values(values) {}

Matrix Matrix::add(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition.");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = values[i][j] + other[i][j];
        }
    }
    return result;
}

Matrix Matrix::multiply(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrices must have compatible dimensions for multiplication.");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result[i][j] += values[i][k] * other[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = values[i][j];
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

std::vector<int>& Matrix::operator[](int row) {
    return values[row];
}

const std::vector<int>& Matrix::operator[](int row) const {
    return values[row];
}

#endif // MATRIX_H