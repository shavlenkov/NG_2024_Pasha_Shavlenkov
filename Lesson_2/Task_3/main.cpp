#include <iostream>

#define MAX_NUMBERS_COUNT 5

using namespace std;

int main() {
    int numbers[MAX_NUMBERS_COUNT] = {0};

    int maxNumber = 0;

    for (int pos = 0; pos < MAX_NUMBERS_COUNT; pos++) {
        int number = 0;

        cout << "Enter amount in " << pos + 1 << " row: ";
        cin >> number;

        numbers[pos] = number;

        if (number > maxNumber) {
            maxNumber = number;
        }
    }

    for (int row = 0; row < maxNumber; row++) {
        for (int col = 0; col < MAX_NUMBERS_COUNT; col++) {
            if (numbers[col] > 0) {
                cout << "*";
            } else {
                cout << " ";
            }

            numbers[col]--;
        }

        cout << endl;
    }
}