#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
    const char CLEAR_COMMAND[] = "clear";
    const int PAUSE_SECONDS  = 1;

    int size = 0;

    cout << "Enter the size of the triangle: ";
    cin >> size;

    system(CLEAR_COMMAND);

    while(1) {
        for(int i = 1; i <= 4; i++) {
            for(int rows = 1; rows <= size; rows++) {
                int stars = 0;
                int spaces = 0;

                if(i == 1 || i == 4) {
                    stars = 0;
                    spaces = rows;
                } else if(i == 2 || i == 3) {
                    stars = -size + (rows + (rows - 1));
                    spaces = size - (rows - 1);
                }

                if(i == 3 || i == 4) {
                    for(; spaces < size; spaces++) {
                        cout << " ";
                    }
                }

                for(; stars < rows; stars++) {
                    cout << "*";
                }

                if(i == 1 || i == 2) {
                    for(; spaces < size; spaces++) {
                        cout << " ";
                    }
                }

                cout << endl;
            }

            sleep(PAUSE_SECONDS);
            system(CLEAR_COMMAND);
        }
    }

    return 0;
}
