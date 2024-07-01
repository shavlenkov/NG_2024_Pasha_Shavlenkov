#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double radius = 1;

    double coord_x = 0;
    double coord_y = 0;

    cout << "Enter the field radius: ";
    cin >> radius;

    cout << "Enter x coordinate: ";
    cin >> coord_x;
    cout << "Enter y coordinate: ";
    cin >> coord_y;

    if(coord_x > radius || coord_y > radius) {
        cout << "You are out of bounds!";

        return 0;
    }

    cout << "Detector blinking frequency: " <<
           sqrt(pow(coord_x, 2) + pow(coord_y, 2));
}