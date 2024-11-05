#include <iostream>

using namespace std;

int main()
{
    const int MAX_LENGTH = 1000;
    const int ASCII_UPPERCASE_RANGE[2] = {65, 90};
    const int ASCII_LOWERCASE_RANGE[2] = {97, 122};

    char str[MAX_LENGTH] = "";

    cout << "Enter string: ";
    cin.getline(str, MAX_LENGTH);

    int insideWord = 0;

    int wordCounter = 0;

    for(int counter = 0; str[counter] != 0; counter++) {
        if(((int)str[counter] >= ASCII_UPPERCASE_RANGE[0] && (int)str[counter] <= ASCII_UPPERCASE_RANGE[1]) ||
            ((int)str[counter] >= ASCII_LOWERCASE_RANGE[0] && (int)str[counter] <= ASCII_LOWERCASE_RANGE[1])) {
            if(!insideWord) {
                insideWord = 1;
                wordCounter++;
            }
        } else {
            insideWord = 0;
        }
    }

    cout << wordCounter << endl;

    return 0;
}
