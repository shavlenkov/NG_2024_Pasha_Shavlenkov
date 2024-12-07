#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Account {
protected:
    int accountId = 0;
    int logIndex = 0;

    static const int MAX_LOGS = 10;

    string logs[MAX_LOGS][2] = {};

    struct AccountStruct {
        int balance = 0;
        int credit = 0;
        int deposit = 0;
        int isActive = 0;
    };

    static const int MAX_ACCOUNTS = 100;

    AccountStruct accounts[MAX_ACCOUNTS];

    string getCurrentDate() {
        time_t currentTime = time(0);
        tm* now = localtime(&currentTime);

        return to_string(now->tm_year + 1900) + "-" +
               to_string(now->tm_mon + 1) + "-" +
               to_string(now->tm_mday) +
               + " " +
               to_string(now->tm_hour) + ":" +
               to_string(now->tm_min) + ":" +
               to_string(now->tm_sec);
    }

    int checkAccountExists(int accountId) {
        if (accountId < 0 || accountId >= MAX_ACCOUNTS || !accounts[accountId].isActive) {
            cout << "Account with ID " << accountId << " does not exist" << endl;

            return 0;
        }

        return 1;
    }

    void addLog(string action) {
        if (logIndex < MAX_LOGS) {
            logs[logIndex][0] = getCurrentDate();
            logs[logIndex][1] = action;

            logIndex++;
        }
    }

public:
    void createAccount() {
        accounts[accountId] = AccountStruct();
        accounts[accountId].isActive = 1;

        cout << "Account with ID " << accountId << " created" << endl;
        addLog("Account with ID " + to_string(accountId) + " created");

        accountId++;
    }

    void deleteAccount(int accountId) {
        if (checkAccountExists(accountId)) {
            accounts[accountId].isActive = 0;
            accounts[accountId] = AccountStruct();

            cout << "Account with ID " << accountId << " deleted" << endl;
            addLog("Account with ID " + to_string(accountId) + " deleted");
        }
    }

    void filterLogsByDate(string date) {
        for(int i = 0; i < logIndex; i++) {
            if(logs[i][0] >= date) {
                cout << logs[i][0] << " - " << logs[i][1] << endl;
            }
        }
    }
};

#endif // ACCOUNT_H
