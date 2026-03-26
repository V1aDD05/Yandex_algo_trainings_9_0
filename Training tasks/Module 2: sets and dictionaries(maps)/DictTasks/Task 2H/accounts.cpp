#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

// void test(){}

void deposit(const string &name, int sum, unordered_map<string, int> &accounts) {
    accounts[name] += sum;
}

void withdraw(const string &name, int sum, unordered_map<string, int> &accounts)
{
    accounts[name] -= sum;
}

void balance(const string &name, unordered_map<string, int> &accounts)
{
    auto it = accounts.find(name);
    if (it == accounts.end()) {
        cout << "ERROR" << endl;
    }
    else {
        cout << it->second << endl;
    }
}

void transfer(const string &name1, const string &name2, int sum, unordered_map<string, int> &accounts) {
    accounts[name1] -= sum;
    accounts[name2] += sum;
}

void income(int p, unordered_map<string, int> &accounts) {
    for (auto& account : accounts) {
        if (account.second > 0) {
            account.second += account.second * p / 100;
        }
    }
}

void wrap(const string &input)
{
    ifstream inputFile(input);

    unordered_map<string, int> accounts;

    string bufStr;
    while (getline(inputFile, bufStr))
    {
        istringstream iss(bufStr);
        string operation;

        iss >> operation;

        if (operation == "DEPOSIT")
        {
            string name;
            int sum;
            iss >> name >> sum;

            deposit(name, sum, accounts);
        }
        else if (operation == "WITHDRAW")
        {
            string name;
            int sum;
            iss >> name >> sum;

            withdraw(name, sum, accounts);
        }
        else if (operation == "BALANCE")
        {
            string name;
            iss >> name;
            balance(name, accounts);
        }
        else if (operation == "TRANSFER")
        {
            string name1, name2;
            int sum;
            iss >> name1 >> name2 >> sum;
            transfer(name1, name2, sum, accounts);
        }
        else if (operation == "INCOME")
        {
            int p;
            iss >> p;
            income(p, accounts);
        }
    }
}

int main()
{
#ifdef LOCAL
    string test;
    // объявить те же переменные, что и в основной части

    //1
    test = "test1.txt";
    cout << "****************" << endl;
    cout << "       TEST 1" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    //2
    test = "test2.txt";
    cout << "****************" << endl;
    cout << "       TEST 2" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    //3
    test = "test3.txt";
    cout << "****************" << endl;
    cout << "       TEST 3" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}