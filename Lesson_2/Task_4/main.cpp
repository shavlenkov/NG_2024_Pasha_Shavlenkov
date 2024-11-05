#include <iostream>

using namespace std;

int main()
{
    const int MAX_LENGTH = 1000;
    const int MAX_SYMBOLS = 95;
    const int ASCII_START = 32;

    char str[MAX_LENGTH] = "";

    cout << "Enter string: ";
    cin.getline(str, MAX_LENGTH);

    int symbolStatistics[MAX_SYMBOLS] = {0};

    for(int counter = 0; str[counter] != 0; counter++) {
        symbolStatistics[str[counter] - ASCII_START]++;
    }

    for(int counter = 0; counter < MAX_SYMBOLS; counter++) {
        if(symbolStatistics[counter] > 0) {
            cout << "'" << (char)(counter + ASCII_START) << "'" << " - " << symbolStatistics[counter] << endl;
        }
    }

    return 0;
}
