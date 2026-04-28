#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

/*
Сложность по времени: O(n), n - количество запросов
Сложность по памяти: O(m), m <= n - количество клиентов
*/

//функция зачисления денег на счёт
void deposit(const std::string &name, int sum, std::unordered_map<std::string, int> &accounts)
{
    accounts[name] += sum;
}

//функция снятия денег со счёта
void withdraw(const std::string &name, int sum, std::unordered_map<std::string, int> &accounts)
{
    accounts[name] -= sum;
}

//функция вывода баланса
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

//функция перевода между счетами 
void transfer(const std::string &name1, const std::string &name2, int sum, std::unordered_map<std::string, int> &accounts)
{
    accounts[name1] -= sum;
    accounts[name2] += sum;
}

//функция начисления процентов
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
    //словарь клиентов (ключ - фамилия, значение - баланс)
    std::unordered_map<std::string, int> accounts;

    std::string bufStr;
    while (getline(std::cin, bufStr))
    {
        std::istringstream iss(bufStr);
        std::string operation;

        //выделяем из считанной строки тип операции
        iss >> operation;

        // вызываем нужную функцию по работе со счётом
        // в зависомости от операции
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