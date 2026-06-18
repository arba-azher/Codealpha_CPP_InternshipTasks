#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Transaction
{
private:
    string type;
    double amt;

public:
    Transaction(){}

    Transaction(string t, double a)
    {
        type = t;
        amt = a;
    }

    void display()
    {
        cout << type << " : Rs." << amt << endl;
    }
};

class Account
{
private:
    int accNo;
    double bal;

    vector<Transaction> hist;

public:
    Account(){}

    Account(int aNo, double b = 0)
    {
        accNo = aNo;
        bal = b;
    }

    int getAccountNumber()
    {
        return accNo;
    }

    double getBalance()
    {
        return bal;
    }

    void deposit(double amt)
    {
        bal += amt;

        hist.push_back(Transaction("Deposit", amt));
    }

    void withdraw(double amt)
    {
        if(amt > bal)
        {
            cout << "Insufficient Balance\n";
            return;
        }

        bal -= amt;

        hist.push_back(Transaction("Withdrawal", amt));
    }

    void transfer(Account &rec, double amt)
    {
        if(amt > bal)
        {
            cout << "Insufficient Balance\n";
            return;
        }

        bal -= amt;
        rec.bal += amt;

        hist.push_back(Transaction("Transfer Sent", amt));

        rec.hist.push_back(Transaction("Transfer Received", amt));
    }

    void showTransactions()
    {
        cout << "\nTransaction History\n";

        for(int i = 0; i < hist.size(); i++)
        {
            hist[i].display();
        }
    }

    void displayAccount()
    {
        cout << "Account Number : " << accNo << endl;
        cout << "Balance : Rs. " << bal << endl;
    }
};

class Customer
{
private:
    int id;
    string name;
    Account acc;

public:
    Customer(){}

    Customer(int i, string n, int aNo) : acc(aNo)
    {
        id = i;
        name = n;
    }

    Account& getAccount()
    {
        return acc;
    }

    void displayCustomer()
    {
        cout << "\nCustomer ID : " << id << endl;
        cout << "Customer Name : " << name << endl;

        acc.displayAccount();
    }
};

int main()
{
    Customer c1(1, "Arba", 1001);
    Customer c2(2, "Azher", 1002);

    c1.getAccount().deposit(50000);

    c1.getAccount().withdraw(20000);

    c1.getAccount().transfer(c2.getAccount(), 3000);

    c1.displayCustomer();

    c1.getAccount().showTransactions();

    cout << "\n";

    c2.displayCustomer();

    c2.getAccount().showTransactions();

    return 0;
}
