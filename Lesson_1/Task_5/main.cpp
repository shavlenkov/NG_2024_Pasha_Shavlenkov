#include <iostream>
#include <cmath>
#include <complex>

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

    if (discriminant > 0) {
        double root_x1 = (-number_b + sqrt(discriminant)) / (2 * number_a);
        double root_x2 = (-number_b - sqrt(discriminant)) / (2 * number_a);

        cout << "The equation has two roots: x1 = " << root_x1 << ", x2 = " << root_x2;
    } else if (discriminant == 0) {
        double root_x = -number_b / (2 * number_a);

        cout << "The equation has one root: x = " << root_x;
    } else {
        complex<double> root_x1 = complex<double>(-number_b, sqrt(-discriminant)) / (2 * number_a);
        complex<double> root_x2 = complex<double>(-number_b, -sqrt(-discriminant)) / (2 * number_a);

        cout << "The equation has two complex roots: x1 = " << root_x1 << ", x2 = " << root_x2;
    }
}