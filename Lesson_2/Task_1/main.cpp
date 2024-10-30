#include <iostream>

using namespace std;

int main()
{
    double numbers[5] = {0.0};

    for(int counter = 0; counter < 5; counter++) {
        cout << "Enter the number " << counter + 1 << ": ";
        cin >> numbers[counter];
    }

    for(int counter = 0; counter < 4; counter++) {
        cout << numbers[counter] << ", ";
    }

    cout << numbers[4];

    return 0;
}
