#include <iostream>

using namespace std;

int main() {
    int salary = 0;

    cout << "How much do you make?" << endl;
    cin >> salary;

    if(salary < 1001) {
        cout << "Work more" << endl;
    }

    if(salary > 1000) {
        if(salary < 1000000) {
            cout << "Good job!" << endl;
        }

        if(salary > 999999) {
            cout << "You are a millionaire!" << endl;
        }
    }

    cout << "But you're great!";
}