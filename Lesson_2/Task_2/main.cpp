#include <iostream>

using namespace std;

int main()
{
    int numbers[5] = {0};

    int maxRows = 0;

    for(int counter = 0; counter < 5; counter++) {
        do {
            cout << "Enter " << counter + 1 << " value: ";
            cin >> numbers[counter];
        } while(numbers[counter] < 0);

        if(maxRows < numbers[counter]){
            maxRows = numbers[counter];
        }
    }

    for(int rows = 0; rows < maxRows; rows++) {
        for(int cols = 0; cols < 5; cols++) {
            if(numbers[cols] - rows  > 0) {
                cout << "*";
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
