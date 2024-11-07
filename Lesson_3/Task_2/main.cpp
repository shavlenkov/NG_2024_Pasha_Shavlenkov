#include <iostream>

using namespace std;

const int MATRIX_SIZE = 3;

struct Matrix {
    int data[MATRIX_SIZE][MATRIX_SIZE] = {};
};

Matrix calculateMatrix(Matrix matrix_1, Matrix matrix_2, char action) {
    Matrix result = {};

    for(int rows = 0; rows < MATRIX_SIZE; rows++) {
        for(int cols = 0; cols < MATRIX_SIZE; cols++) {
            switch(action) {
                case '+':
                    result.data[rows][cols] = matrix_1.data[rows][cols] + matrix_2.data[rows][cols];
                    break;
                case '-':
                    result.data[rows][cols] = matrix_1.data[rows][cols] - matrix_2.data[rows][cols];
                    break;
                case '*':
                    for(int counter = 0; counter < MATRIX_SIZE; counter++) {
                        result.data[rows][cols] += matrix_1.data[cols][counter] * matrix_2.data[counter][cols];
                    }
                    break;
                default:
                    break;
            }
        }
    }

    return result;
}

Matrix inputMatrix() {
    Matrix matrix = {};

    cout << "Enter the elements of the matrix (" << MATRIX_SIZE << "x" << MATRIX_SIZE << "):" << endl;

    for(int rows = 0; rows < MATRIX_SIZE; rows++) {
        for(int cols = 0; cols < MATRIX_SIZE; cols++) {
            cout << "Enter element [" << rows + 1 << "][" << cols + 1 << "]: ";
            cin >> matrix.data[rows][cols];
        }
    }

    return matrix;
}

void printMatrix(Matrix matrix) {
    for(int rows = 0; rows < MATRIX_SIZE; rows++) {
        for(int cols = 0; cols < MATRIX_SIZE; cols++) {
            cout << matrix.data[rows][cols] << " ";
        }

        cout << endl;
    }
}

int main() {
    Matrix matrix_1 = inputMatrix();
    Matrix matrix_2 = inputMatrix();

    char operation = ' ';

    do {
        cout << "Enter operation (+, -, *): ";
        cin >> operation;
    } while(operation != '+' && operation != '-' && operation != '*');

    printMatrix(calculateMatrix(matrix_1, matrix_2, operation));

    return 0;
}
