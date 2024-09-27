#include <iostream>
#include <vector>

double determinant(std::vector<double>& matx, int size_matx) {
    for (int i = 0; i < size_matx; ++i) {
        for (int j = i + 1; j < size_matx; ++j) {
            if (matx[i * size_matx + i] == 0) {
                std::cerr << " деление на ноль." << std::endl;
                return 0; 
            }
            double s = matx[j * size_matx + i] / matx[i * size_matx + i];
            for (int k = i; k < size_matx; k++) {
                matx[j * size_matx + k] -= s * matx[i * size_matx + k];
            }
        }
    }

    
    double det = 1;
    for (int l = 0; l < size_matx; ++l) {
        det *= matx[l * size_matx + l]; 
    }

    return det;
}

int main() {
    int matrix_size;

    std::cout << "Размер матрицы: ";
    std::cin >> matrix_size;

    std::vector<double> matrix(matrix_size * matrix_size);

    std::cout << "Введите элементы матрицы:" << std::endl;
    for (int i = 0; i < matrix_size * matrix_size; ++i) {
        std::cin >> matrix[i];
    }

    std::cout << "Определитель: " << determinant(matrix, matrix_size) << std::endl;
    return 0;
}