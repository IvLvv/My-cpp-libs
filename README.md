# My cpp libs

## First Library: Matrix Operations

### Overview

The first library in this repository is designed to provide matrix operations. It includes a set of functions and classes that facilitate matrix addition, multiplication, transposition, determinant calculation, and finding the inverse of a matrix.

### Features

- **Matrix Addition**: Add two matrices of the same or different dimensions.
- **Matrix Multiplication**: Multiply two matrices with compatible dimensions.
- **Matrix Transposition**: Transpose a given matrix.
- **Matrix Determinant**: Calculate the determinant of a square matrix.
- **Matrix Inverse**: Find the inverse of a square matrix.
- **Matrix Printing**: Print the matrix to the console.

### Installation

To use this library, include the following file in your project:

```cpp
#include "matrix.h"
```

### Usage

Here is an example of how to use the Matrix library:

```cpp
#include "matrix.h"
#include <iostream>

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
```

This will output:

```
Sum of matrices:
6 8 
10 12 

Product of matrices:
19 22 
43 50 

Transpose of matrix 1:
1 3 
2 4 

Determinant of matrix 1: -2

Inverse of matrix 1:
-2 1 
1.5 -0.5 
```

For more detailed usage, refer to the comments and documentation within the `matrix.h` file.

Welcome to My C++ Libraries repository. This collection includes various C++ libraries that I have developed.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

This repository contains a set of C++ libraries designed to help with various programming tasks. Each library is self-contained and can be used independently.

## Installation

To install any of the libraries, clone the repository and include the desired library in your project:

```sh
git clone https://github.com/yourusername/My-cpp-libs.git
```

## Usage

Each library comes with its own documentation and examples. Refer to the specific library's README file for detailed usage instructions.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes. Ensure that your code follows the project's coding standards and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.