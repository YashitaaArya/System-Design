#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Account{
    public:
        virtual void withdraw(double amount)=0; // pure virtual function
        virtual void deposit(double amount)=0; // pure virtual function 
};

class SavingsAccount : public Account{
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

class CurrentAccount : public Account{
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

class FixedTermAccount : public Account{
    private:
        double balance;
    public:
        FixedTermAccount(){
            balance = 0;
        }
        void withdraw(double amount) override{
            throw logic_error("Withdrawals not allowed from fixed term account until maturity!");
        }
        void deposit(double amount) override{
            balance += amount;
            cout << "Deposited $" << amount << " in fixed term account. New balance: $" << balance << endl;
        }
};

class BankClient{
    private:
        vector<Account*> accounts;
    public:
        BankClient(vector<Account*> accounts){
            this->accounts = accounts;
        }
        void processTransactions(){
            for(Account* account : accounts){
                account->deposit(1000);
                try{
                    account->withdraw(200);
                    account->withdraw(900); // This will show insufficient funds for savings and current accounts
                }catch(const logic_error& e){
                    cout << "Exception: " << e.what() << endl;
                }
            }
        }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount()); 
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());
    BankClient* client=new BankClient(accounts);
    client->processTransactions(); //throws exception for fixed term account when trying to withdraw    
    return 0;
}