#include <iostream>
#include <sstream> //std::istringstream
#include <string>
#include <map>

int main()
{
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

    return 0;
}