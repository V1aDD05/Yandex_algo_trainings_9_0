#include <iostream>
#include <sstream> //std::istringstream
#include <string>
#include <map>

/*
Сложность по времени: O(n), n - количество запросов
Сложность по памяти: O(m*k), где
m - количество клиентов, k - количество наименований товаров
*/

//функция заполнения "базы данных"
std::map<std::string, std::map<std::string, long int>> fillDB()
{
    // двумерный словарь, имитирующий "базу данных":
    // для кадого клиента хранится список наимнований товаров,
    // для каждого наименования товара - количество купленного
    std::map<std::string, std::map<std::string, long int>> dataBase;

    std::string customer;
    std::string subject;
    long int subQuantity;

    std::string bufStr;
    while (std::getline(std::cin, bufStr))
    {
        std::istringstream iss(bufStr);
        iss >> customer >> subject >> subQuantity;
        dataBase[customer][subject] += subQuantity;
    }

    return dataBase;
}

//функция вывода данных
void outputData(const std::map<std::string, std::map<std::string, long int>> &dataBase)
{
    // выводим информацию по каждому покупателю
    for (const auto &person : dataBase)
    {
        std::cout << person.first << ":" << std::endl;
        for (const auto &product : person.second)
        {
            // защита от дурака, контест это не проверяет
            if (product.second != 0)
            {
                std::cout << product.first << " " << product.second << std::endl;
            }
        }
    }
}

int main()
{
    //двумерный словарь, имитирующий "базу данных":
    //для кадого клиента хранится список наимнований товаров,
    //для каждого наименования товара - количество купленного
    std::map<std::string, std::map<std::string, long int>> dataBase = fillDB();

    // выводим информацию по каждому покупателю
    outputData(dataBase);

    return 0;
}