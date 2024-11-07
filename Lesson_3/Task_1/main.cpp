#include <iostream>

using namespace std;

void drawSymbols(int quantity, char symbol)
{
    if(quantity == 0) {
        return;
    }

    if(quantity < 0) {
        quantity = quantity * -1;
    }

    quantity--;

    cout << symbol;

    drawSymbols(quantity, symbol);
}

void drawRows(int level, int size)
{
    if(level == size) {
        drawSymbols(size - 1, ' ');
        drawSymbols(1, '*');

        return;
    }

    level++;

    drawSymbols(size - level, ' ');
    drawSymbols((level * 2) - 1, '*');

    cout << endl;

    drawRows(level, size);
}

void drawChristmasTree(int size)
{
    drawRows(0, size);
}

int main()
{
    int size = 0;

    do {
        cout << "Enter the size of the Christmas tree: ";
        cin >> size;
    } while(size < 0);

    drawChristmasTree(size);

    return 0;
}
