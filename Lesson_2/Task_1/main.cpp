#include <iostream>

#define MAX_CARDS_COUNT 10

using namespace std;

int main() {
    int cards[MAX_CARDS_COUNT] = {0};

    cout << "BANK" << endl;
    cout << "------------------------------------" << endl;
    cout << "1. Put money" << endl;
    cout << "2. Withdraw money" << endl;
    cout << "3. Show the amount on all cards" << endl;
    cout << "4. Show the minimum amount of money" << endl;
    cout << "5. Show the maximum amount of money" << endl;
    cout << "6. Exit" << endl;

    while (true) {
        int command = 6;

        cout << "Enter the command: ";
        cin >> command;

        switch (command) {
            case 1:
            case 2: {
                int number = 0;

                cout << "Enter the card number: ";
                cin >> number;

                if (number < 0 || number >= MAX_CARDS_COUNT) {
                    cout << "Invalid card number" << endl;

                    break;
                }

                int amount = 0;

                cout << "Enter the amount of money: ";
                cin >> amount;

                if (amount <= 0) {
                    cout << "The amount must be a positive number" << endl;

                    break;
                }

                if (command == 1) {
                    cards[number] += amount;
                } else {
                    if (cards[number] >= amount) {
                        cards[number] -= amount;
                    } else {
                        cout << "Not enough funds" << endl;
                    }
                }

                break;
            }
            case 3: {
                int amount = 0;

                for (int card_number = 0; card_number < MAX_CARDS_COUNT; card_number++) {
                    amount += cards[card_number];
                }

                cout << "Amount of money: " << amount << endl;

                break;
            }
            case 4: {
                int minAmount = 0;

                for (int card_number = 0; card_number < MAX_CARDS_COUNT; card_number++) {
                    if (cards[card_number] < minAmount) {
                        minAmount = cards[card_number];
                    }
                }

                cout << "Minimum amount of money: " << minAmount << endl;

                break;
            }
            case 5: {
                int maxAmount = 0;

                for (int card_number = 0; card_number < MAX_CARDS_COUNT; card_number++) {
                    if (cards[card_number] > maxAmount) {
                        maxAmount = cards[card_number];
                    }
                }

                cout << "Maximum amount of money: " << maxAmount << endl;

                break;
            }
            case 6:
                return 0;
            default:
                cout << "Invalid command" << endl;

                break;
        }
    }
}
