#include <iostream>

using namespace std;

int main()
{
    string allNumbers = "";

    for(int counter = 0; counter < 5; counter++) {
        string oneNumber = "";

        cout << "Enter the number " << counter + 1 << ": ";
        cin >> oneNumber;

        allNumbers += oneNumber;

        if(counter < 4) {
            allNumbers += ", ";
        }
    }

    cout << allNumbers;

    return 0;
}
