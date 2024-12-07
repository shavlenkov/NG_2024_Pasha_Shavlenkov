#ifndef BANK_H
#define BANK_H

#include <iostream>
#include "./Account.h"

using namespace std;

class Bank : public Account {
public:
    void depositMoney(int accountId, int amount) {
        if(amount <= 0) {
            return;
        }

        if(checkAccountExists(accountId)) {
            accounts[accountId].balance += amount;

            cout << "Added " << amount << " money to account with ID " << accountId << endl;
            addLog("Added " + to_string(amount) + " money to account with ID " + to_string(accountId));
        }
    }

    void withdrawMoney(int accountId, int amount) {
        if(amount <= 0) {
            return;
        }

        if(checkAccountExists(accountId) && accounts[accountId].balance >= amount) {
            accounts[accountId].balance -= amount;

            cout << "Withdrawn " << amount << " money from account with ID " << accountId << endl;
            addLog("Withdrawn " + to_string(amount) + " money from account with ID " + to_string(accountId));
        } else {
            cout << "Failed to withdraw " << amount << " money from account with ID " << accountId << endl;
        }
    }

    void takeCredit(int accountId, int amount) {
        if(amount <= 0) {
            return;
        }

        if(checkAccountExists(accountId)) {
            accounts[accountId].credit += amount;
            accounts[accountId].balance += amount;

            cout << "Credit of " << amount << " money taken for account with ID " << accountId << endl;
            addLog("Credit of " + to_string(amount) + " money taken for account with ID " + to_string(accountId));
        }
    }

    void repayCredit(int accountId, int amount) {
        if(amount <= 0) {
            return;
        }

        if(checkAccountExists(accountId) && accounts[accountId].credit >= amount && amount <= accounts[accountId].balance) {
            accounts[accountId].credit -= amount;
            accounts[accountId].balance -= amount;

            cout << "Credit of " << amount << " money repaid for account with ID " << accountId << endl;
            addLog("Credit of " + to_string(amount) + " money repaid for account with ID " + to_string(accountId));
        } else {
            cout << "Failed to repay credit of " << amount << " money for account with ID " << accountId << endl;
        }
    }

    void placeDeposit(int accountId, int amount) {
        if(amount <= 0) {
            return;
        }

        if(checkAccountExists(accountId) && accounts[accountId].balance >= amount) {
            accounts[accountId].deposit += amount;
            accounts[accountId].balance -= amount;

            cout << "Deposit of " << amount << " money placed for account with ID " << accountId << endl;
            addLog("Deposit of " + to_string(amount) + " money placed for account with ID " + to_string(accountId));
        }
    }

    void withdrawDeposit(int accountId, int amount) {
        if(amount <= 0) {
            return;
        }

        if(checkAccountExists(accountId) && accounts[accountId].deposit >= amount) {
            accounts[accountId].deposit -= amount;
            accounts[accountId].balance += amount;

            cout << "Deposit of " << amount << " money withdrawn from account with ID " << accountId << endl;
            addLog("Deposit of " + to_string(amount) + " money withdrawn from account with ID " + to_string(accountId));
        } else {
            cout << "Failed to withdraw deposit of " << amount << " money from account with ID " << accountId << endl;
        }
    }
};

#endif // BANK_H
