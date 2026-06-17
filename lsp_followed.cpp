#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DepositOnlyAccount{
    public:
        virtual void deposit(double amount)=0; // pure virtual function
};

class WithdrawableAccount : public DepositOnlyAccount{
    public:
        virtual void withdraw(double amount)=0; // pure virtual function
};

class SavingsAccount : public WithdrawableAccount{
    private:
        double balance;
    public:
        SavingsAccount(){
            balance = 0;
        }
        void withdraw(double amount) override{
            if(amount > balance){
                cout << "Insufficient funds!" << endl;
                return;
            }else{
                balance -= amount;
                cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
            }
        }
        void deposit(double amount) override{
            balance += amount;
            cout << "Deposited $" << amount << " in savings account. New balance: $" << balance << endl;
        }
};

class CurrentAccount : public WithdrawableAccount{
    private:
        double balance;
    public:
        CurrentAccount(){
            balance = 0;
        }
        void withdraw(double amount) override{
            if(amount > balance){
                cout << "Insufficient funds!" << endl;
                return;
            }else{
                balance -= amount;
                cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
            }
        }
        void deposit(double amount) override{
            balance += amount;
            cout << "Deposited $" << amount << " in current account. New balance: $" << balance << endl;
        }
};

class FixedTermAccount : public DepositOnlyAccount{
    private:
        double balance;
    public:
        FixedTermAccount(){
            balance = 0;
        }
        void deposit(double amount) override{
            balance += amount;
            cout << "Deposited $" << amount << " in fixed term account. New balance: $" << balance << endl;
        }
};

class BankClient{
    private:
        vector<WithdrawableAccount*> withdrawableAccounts;
        vector<DepositOnlyAccount*> depositOnlyAccounts;
    public:
        BankClient(vector<WithdrawableAccount*> withdrawableAccounts, vector<DepositOnlyAccount*> depositOnlyAccounts){
            // constructor body (if needed)
            this->withdrawableAccounts = withdrawableAccounts;
            this->depositOnlyAccounts = depositOnlyAccounts;
        }

        void processTransactions(){
            for(WithdrawableAccount* acc : withdrawableAccounts){
                acc->deposit(1000);
                acc->withdraw(500);
            }
            for(DepositOnlyAccount* acc : depositOnlyAccounts){
                acc->deposit(5000);
            }
        }
};

int main(){
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());
    BankClient* client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions();
    return 0;
}