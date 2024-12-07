#include "Bank.h"

using namespace std;

int main() {
    Bank bank = {};

    cout << "========= BANK ===========" << endl;

    do {
        int command = 0;

        int accountId = 0;
        int amount = 0;

        cout << "1. Create account" << endl;
        cout << "2. Delete account" << endl;
        cout << "3. Deposit money" << endl;
        cout << "4. Withdraw money" << endl;
        cout << "5. Take credit" << endl;
        cout << "6. Repay credit" << endl;
        cout << "7. Place deposit" << endl;
        cout << "8. Withdraw deposit" << endl;
        cout << "9. Filter logs by date" << endl;
        cout << "Enter command: ";

        cin >> command;

        switch(command) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                cout << "Enter account ID: ";
                cin >> accountId;
                bank.deleteAccount(accountId);
                break;
            case 3:
                cout << "Enter account ID: ";
                cin >> accountId;
                cout << "Enter amount of money: ";
                cin >> amount;
                bank.depositMoney(accountId, amount);
                break;
            case 4:
                cout << "Enter account ID: ";
                cin >> accountId;
                cout << "Enter amount of money: ";
                cin >> amount;
                bank.withdrawMoney(accountId, amount);
                break;
            case 5:
                cout << "Enter account ID: ";
                cin >> accountId;
                cout << "Enter amount of money: ";
                cin >> amount;
                bank.takeCredit(accountId, amount);
                break;
            case 6:
                cout << "Enter account ID: ";
                cin >> accountId;
                cout << "Enter amount of money: ";
                cin >> amount;
                bank.repayCredit(accountId, amount);
                break;
            case 7:
                cout << "Enter account ID: ";
                cin >> accountId;
                cout << "Enter amount of money: ";
                cin >> amount;
                bank.placeDeposit(accountId, amount);
                break;
            case 8:
                cout << "Enter account ID: ";
                cin >> accountId;
                cout << "Enter amount of money: ";
                cin >> amount;
                bank.withdrawDeposit(accountId, amount);
                break;
            case 9:
                string date = "";

                cout << "Enter date to filter by: ";
                cin.ignore();
                getline(cin, date);
                bank.filterLogsByDate(date);
                break;
        }
    } while (true);
}
