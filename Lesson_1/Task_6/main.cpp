#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
    const int PAUSE_SECONDS = 1;

    int size = 0;

    do {
        cout << "Enter the size of the triangle: ";
        cin >> size;
    } while(size < 0);

    system("clear");

    while(1) {
        for(int triangles = 1; triangles <= 4; triangles++) {
            for(int rows = 1; rows <= size; rows++) {
                int stars = 0;
                int spaces = 0;

                if(triangles == 1 || triangles == 4) {
                    stars = 0;
                    spaces = rows;
                } else if(triangles == 2 || triangles == 3) {
                    stars = -size + (rows + (rows - 1));
                    spaces = size - (rows - 1);
                }

                if(triangles == 3 || triangles == 4) {
                    for(; spaces < size; spaces++) {
                        cout << " ";
                    }
                }

                for(; stars < rows; stars++) {
                    cout << "*";
                }

                if(triangles == 1 || triangles == 2) {
                    for(; spaces < size; spaces++) {
                        cout << " ";
                    }
                }

                cout << endl;
            }

            sleep(PAUSE_SECONDS);
            system("clear");
        }
    }

    return 0;
}
