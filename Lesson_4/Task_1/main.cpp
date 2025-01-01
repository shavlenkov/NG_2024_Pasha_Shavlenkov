#include "Bank.h"

using namespace std;

int getAccountId() {
    int accountId = 0;

    cout << "Enter account ID: ";
    cin >> accountId;

    if(accountId < 0) {
        return getAccountId();
    }

    return accountId;
}

int getAmount() {
    int amount = 0;

    cout << "Enter amount of money: ";
    cin >> amount;

    if(amount <= 0) {
        return getAmount();
    }

    return amount;
}

int main() {
    Bank bank = {};

    cout << "========= BANK ===========" << endl;

    do {
        int command = 0;

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
                bank.deleteAccount(getAccountId());
                break;
            case 3:
                bank.depositMoney(getAccountId(), getAmount());
                break;
            case 4:
                bank.withdrawMoney(getAccountId(), getAmount());
                break;
            case 5:
                bank.takeCredit(getAccountId(), getAmount());
                break;
            case 6:
                bank.repayCredit(getAccountId(), getAmount());
                break;
            case 7:
                bank.placeDeposit(getAccountId(), getAmount());
                break;
            case 8:
                bank.withdrawDeposit(getAccountId(), getAmount());
                break;
            case 9:
                string date = "";

                cout << "Enter date to filter by: ";
                cin.ignore();
                getline(cin, date);
                bank.filterLogsByDate(date);
                break;
        }
    } while(true);

    return 0;
}
