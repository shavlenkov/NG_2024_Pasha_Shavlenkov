#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double number_a = 0;
    double number_b = 0;
    double number_c = 0;

    cout << "Enter the number a: ";
    cin >> number_a;
    cout << "Enter the number b: ";
    cin >> number_b;
    cout << "Enter the number c: ";
    cin >> number_c;

    double discriminant = pow(number_b, 2) - 4 * number_a * number_c;

    if(discriminant > 0) {
        double x1 = (-number_b + sqrt(discriminant)) / (2 * number_a);
        double x2 = (-number_b - sqrt(discriminant)) / (2 * number_a);

        if (discriminant == 0) {
            cout << "The equation has one root: x =" << x1;
        } else {
            cout << "The equation has two roots: x1 = " << x1 << ", x2 = " << x2;
        }
    } else {
        cout << "The equation has no real roots";
    }
}
