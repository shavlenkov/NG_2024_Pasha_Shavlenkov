#include <iostream>

using namespace std;

int main()
{
    double number_1 = 0.0;
    double number_2 = 0.0;

    int action = 0;

    cout << "Enter the number 1: ";
    cin >> number_1;

    cout << "Enter the number 2: ";
    cin >> number_2;

    do {
        cout << "Select an action:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> action;
    } while(action < 1 || 4 < action);

    cout << "Result: ";

    switch(action) {
        case 1:
            cout << number_1 + number_2;
            break;
        case 2:
            cout << number_1 - number_2;
            break;
        case 3:
            cout << number_1 * number_2;
            break;
        case 4:
            if(number_2 == 0) {
                cout << "You can't divide by zero!";
            } else {
                cout << number_1 / number_2;
            }
            break;
    }

    return 0;
}
