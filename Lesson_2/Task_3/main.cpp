#include <iostream>

using namespace std;

int main()
{
    int numbers[20] = {0};

    int counter = 0;
    int maxNumber = 0;

    do {
        do {
            cout << "Enter value: ";
            cin >> numbers[counter];
        } while(numbers[counter] < 0);

        if (numbers[counter] > maxNumber) {
            maxNumber = numbers[counter];
        }

        counter++;
    } while (numbers[counter - 1] != 0 && counter < 20);

    for(int rows = 0; rows < counter; rows++) {
        for(int spaces = 0; spaces < (maxNumber - numbers[rows]) / 2; spaces++) {
            cout << " ";
        }

        for(int stars = 0; stars < numbers[rows]; stars++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
