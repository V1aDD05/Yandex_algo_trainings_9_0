#include <iostream>
#include <string>
#include <unordered_map>

/*
Сложность по времени: O(n), где
n - количество пар синонимов
Сложность по памяти: O(n).
*/

// функция заполнения словаря синонимов
std::unordered_map<std::string, std::string> enterDictionary(const int quantity, std::istream &in)
{
    std::unordered_map<std::string, std::string> synDict;
    std::string first, second;

    for (int i = 0; i < quantity; ++i)
    {
        in >> first >> second;
        synDict[first] = second;
        synDict[second] = first;
    }

    return synDict;
}

int main()
{
    

    //считываем количество пар слов
    int quantity;
    std::cin >> quantity;
    std::cin.ignore();

    // заполняем словарь синонимов
    // словарь синонимов
    std::unordered_map<std::string, std::string> synDict = enterDictionary(quantity, std::cin);

    //выводим синоним введённого слова
    std::string request;
    std::cin >> request;
    std::cout << synDict[request] << std::endl;

    return 0;
}