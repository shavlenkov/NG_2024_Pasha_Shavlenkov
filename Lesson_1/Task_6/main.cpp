#include <iostream>

using namespace std;

int main() {
    int size = 0;

    cout << "Enter size: ";
    cin >> size;

    if(size >= 0) {

        for(int row = 0; row < size; row++) {
            for(int col = 0; col < size + row; col++) {
                if(col >= (size - 1) - row) {
                    cout << "*";
                } else {
                    cout << " ";
                }

            }

            cout << endl;
        }

        for(int row = 0; row < size - 1; row++) {
            cout << " ";
        }

        cout << "*";

    } else {
        cout << "The size cannot be negative";
    }
}