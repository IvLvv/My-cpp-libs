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

    // Функция для нахождения определителя
    int determinant() const;

    // Функция для нахождения обратной матрицы
    Matrix inverse() const;

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

    // Вспомогательная функция для нахождения определителя
    int determinant(const std::vector<std::vector<int>>& matrix) const;

    // Вспомогательная функция для нахождения алгебраического дополнения
    std::vector<std::vector<int>> getMinor(const std::vector<std::vector<int>>& matrix, int row, int col) const;
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

int Matrix::determinant() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square to calculate determinant.");
    }
    return determinant(values);
}

int Matrix::determinant(const std::vector<std::vector<int>>& matrix) const {
    int n = matrix.size();
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    int det = 0;
    for (int p = 0; p < n; ++p) {
        std::vector<std::vector<int>> minor = getMinor(matrix, 0, p);
        det += matrix[0][p] * determinant(minor) * (p % 2 == 0 ? 1 : -1);
    }
    return det;
}

std::vector<std::vector<int>> Matrix::getMinor(const std::vector<std::vector<int>>& matrix, int row, int col) const {
    int n = matrix.size();
    std::vector<std::vector<int>> minor(n - 1, std::vector<int>(n - 1));
    for (int i = 0; i < n; ++i) {
        if (i == row) continue;
        for (int j = 0; j < n; ++j) {
            if (j == col) continue;
            minor[i < row ? i : i - 1][j < col ? j : j - 1] = matrix[i][j];
        }
    }
    return minor;
}

Matrix Matrix::inverse() const {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square to calculate inverse.");
    }
    int det = determinant();
    if (det == 0) {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }
    int n = rows;
    Matrix result(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::vector<std::vector<int>> minor = getMinor(values, i, j);
            result.values[j][i] = determinant(minor) * ((i + j) % 2 == 0 ? 1 : -1) / det;
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