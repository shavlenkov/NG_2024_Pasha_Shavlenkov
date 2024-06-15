#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int operation = 0;

    double number_1 = 0;
    double number_2 = 0;

    cout << "1. addition" << endl
         << "2. subtraction" << endl
         << "3. multiplication" << endl
         << "4. division" << endl
         << "5. a degree squared" << endl
         << "6. root" << endl;

    cout << "Select an operation: ";
    cin >> operation;

    if(operation >= 1 && operation <= 6) {
        cout << "Enter the first number: ";
        cin >> number_1;

        if(operation >= 1 && operation <= 4) {
            cout << "Enter the second number: ";
            cin >> number_2;
        }
    }

    if((operation == 4 && number_2 == 0) || (operation == 6 && number_1 < 0)) {
        cout << "Error: ";
    } else {
        cout << "Result: ";
    }

    switch (operation) {
        case 1:
            cout << number_1 + number_2 << endl;
        break;
        case 2:
            cout << number_1 - number_2 << endl;
        break;
        case 3:
            cout << number_1 * number_2 << endl;
        break;
        case 4:
            if(number_2 != 0) {
                cout << number_1 / number_2 << endl;
            } else {
                cout << "Division by zero is not allowed";
            }
        break;
        case 5:
            cout << pow(number_1, 2) << endl;
        break;
        case 6:
            if (number_1 >= 0) {
                cout << sqrt(number_1) << endl;
            } else {
                cout << "Cannot take the square root of a negative number" << endl;
            }
        break;
        default:
            cout << "Invalid operation" << endl;
    }
}