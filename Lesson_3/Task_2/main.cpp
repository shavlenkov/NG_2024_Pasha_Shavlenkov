#include <iostream>

using namespace std;

const int MATRIX_SIZE = 3;

struct Matrix {
    int data[MATRIX_SIZE][MATRIX_SIZE] = {};

    void input() {
        cout << "Enter the elements of the matrix (" << MATRIX_SIZE << "x" << MATRIX_SIZE << "):" << endl;

        for(int rows = 0; rows < MATRIX_SIZE; rows++) {
            for(int cols = 0; cols < MATRIX_SIZE; cols++) {
                cout << "Enter element [" << rows + 1 << "][" << cols + 1 << "]: ";
                cin >> data[rows][cols];
            }
        }
    }

    void print() {
        for(int rows = 0; rows < MATRIX_SIZE; rows++) {
            for(int cols = 0; cols < MATRIX_SIZE; cols++) {
                cout << data[rows][cols] << " ";
            }

            cout << endl;
        }
    }

    Matrix calculate(Matrix matrix, char action) {
        Matrix result = {};

        for(int rows = 0; rows < MATRIX_SIZE; rows++) {
            for(int cols = 0; cols < MATRIX_SIZE; cols++) {
                switch(action) {
                    case '+':
                        result.data[rows][cols] = data[rows][cols] + matrix.data[rows][cols];
                        break;
                    case '-':
                        result.data[rows][cols] = data[rows][cols] - matrix.data[rows][cols];
                        break;
                    case '*':
                        for(int counter = 0; counter < MATRIX_SIZE; counter++) {
                            result.data[rows][cols] += data[cols][counter] * matrix.data[counter][cols];
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        return result;
    }
};

int main() {
    Matrix matrix_1 = {};
    Matrix matrix_2 = {};

    cout << "Matrix 1:" << endl;
    matrix_1.input();

    cout << "Matrix 2:" << endl;
    matrix_2.input();

    char operation = ' ';

    do {
        cout << "Enter operation (+, -, *): ";
        cin >> operation;
    } while(operation != '+' && operation != '-' && operation != '*');

    matrix_1.calculate(matrix_2, operation).print();

    return 0;
}
