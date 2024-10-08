#include <iostream>

using namespace std;

int main()
{
    int salary = 0;

    cout << "Enter your salary: ";
    cin >> salary;

    if(salary < 1000) {
        cout << "Work more";
    }

    if(salary > 999) {
        if(salary < 1000000) {
            cout << "You're doing great";
        }

        if(salary > 999999) {
            cout << "You're a millionaire";
        }
    }

    return 0;
}
