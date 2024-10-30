#include <iostream>

using namespace std;

int main()
{
    int size = 0;

    do {
        cout << "Enter the size of the Christmas tree: ";
        cin >> size;
    } while(size < 0);

    for(int rows = 1; rows <= size; rows++) {
        for(int spaces = rows; spaces < size; spaces++) {
            cout << " ";
        }

        for(int stars = 1; stars < rows * 2; stars++) {
            cout << "*";
        }

        cout << endl;
    }

    for(int spaces = 1; spaces < size; spaces++) {
        cout << " ";
    }

    cout << "*";

    return 0;
}
