#include <iostream>
#include <cstdlib>
#include <unistd.h>

#define CLEAR_COMMAND "clear"
#define PAUSE_SECONDS 1

using namespace std;

int main()
{
    int size = 0;

    cout << "Enter the size of the triangle: ";
    cin >> size;

    system(CLEAR_COMMAND);

    for(int rows = 1; rows <= size; rows++) {
        for(int stars = 0; stars < rows; stars++) {
            cout << "*";
        }

        cout << endl;
    }

    sleep(PAUSE_SECONDS);
    system(CLEAR_COMMAND);

    for(int rows = size; rows > 0; rows--) {
        for(int stars = 0; stars < rows; stars++) {
            cout << "*";
        }

        cout << endl;
    }

    sleep(PAUSE_SECONDS);
    system(CLEAR_COMMAND);

    for(int rows = 0; rows < size; rows++) {
        for(int spaces = 0; spaces < rows; spaces++) {
            cout << " ";
        }

        for(int stars = rows; stars < size; stars++) {
            cout << "*";
        }

        cout << endl;
    }

    sleep(PAUSE_SECONDS);
    system(CLEAR_COMMAND);

    for(int rows = size; rows > 0; rows--) {
        for(int spaces = 1; spaces < rows; spaces++) {
            cout << " ";
        }

        for(int stars = rows; stars <= size; stars++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
