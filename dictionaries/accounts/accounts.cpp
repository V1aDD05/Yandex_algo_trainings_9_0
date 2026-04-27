#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

void deposit(const std::string &name, int sum, std::unordered_map<std::string, int> &accounts)
{
    accounts[name] += sum;
}

void withdraw(const std::string &name, int sum, std::unordered_map<std::string, int> &accounts)
{
    accounts[name] -= sum;
}

void balance(const std::string &name, std::unordered_map<std::string, int> &accounts)
{
    auto it = accounts.find(name);
    if (it == accounts.end()) {
        std::cout << "ERROR" << std::endl;
    }
    else {
        std::cout << it->second << std::endl;
    }
}

void transfer(const std::string &name1, const std::string &name2, int sum, std::unordered_map<std::string, int> &accounts)
{
    accounts[name1] -= sum;
    accounts[name2] += sum;
}

void income(int p, std::unordered_map<std::string, int> &accounts)
{
    for (auto& account : accounts) {
        if (account.second > 0) {
            account.second += account.second * p / 100;
        }
    }
}

int main()
{
    std::unordered_map<std::string, int> accounts;

    std::string bufStr;
    while (std::getline(std::cin, bufStr))
    {
        std::istringstream iss(bufStr);
        std::string operation;

        iss >> operation;

        if (operation == "DEPOSIT")
        {
            std::string name;
            int sum;
            iss >> name >> sum;

            deposit(name, sum, accounts);
        }
        else if (operation == "WITHDRAW")
        {
            std::string name;
            int sum;
            iss >> name >> sum;

            withdraw(name, sum, accounts);
        }
        else if (operation == "BALANCE")
        {
            std::string name;
            iss >> name;
            balance(name, accounts);
        }
        else if (operation == "TRANSFER")
        {
            std::string name1, name2;
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

    return 0;
}