#include <iostream>

#define MAX_NUMBERS_COUNT 20

using namespace std;

int main() {
    int numbers[MAX_NUMBERS_COUNT] = {0};

    int rows = 0;
    int maxNumber = 0;
    int number = 1;

    while (rows < MAX_NUMBERS_COUNT && number != 0) {
        cout << "Enter value: ";
        cin >> number;

        numbers[rows] = number;

        if (number > maxNumber) {
            maxNumber = number;
        }

        rows++;
    }

    for (int row = 0; row < rows; row++) {
        for (int space = 0; space < (maxNumber - numbers[row]) / 2; space++) {
            cout << " ";
        }

        for (int star = 0; star < numbers[row]; star++) {
            cout << "*";
        }

        cout << endl;
    }
}