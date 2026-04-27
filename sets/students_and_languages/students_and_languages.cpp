#include <iostream>
#include <string>
#include <unordered_map>
#include <tuple>
#include <vector>


/*
Сложность по времени: O(N)
Сложность по памяти: O(N).
*/

// функция определения общеизвестных и уникальных языков и их количества по словарю языков
std::tuple<int, int, std::vector<std::string>, std::vector<std::string>> discoverLangKnowledge(const int studentsQuantity, const std::unordered_map<std::string, int> &langMap)
{

    //общих языков, уникальных языков, список общих, список уникальных
    int commonLang, uniqueLang;
    std::vector<std::string> commonLangVec, uniqueLangVec;

    commonLang = 0;
    uniqueLang = 0;

    for (const auto &pair : langMap) {
        if (pair.second == studentsQuantity) {
            ++commonLang;
            commonLangVec.push_back(pair.first);
        }
        uniqueLangVec.push_back(pair.first);
    }

    uniqueLang = static_cast<int>(uniqueLangVec.size());

    return {commonLang, uniqueLang, commonLangVec, uniqueLangVec};
}


int main()
{

    // словарь языков (ключ - язык, значение - частота знания языка)
    std::unordered_map<std::string, int> langMap;

    int studentsQuantity;
    std::cin >> studentsQuantity;
    for (int i = 0; i < studentsQuantity; ++i)
    {
        int langQuantity;
        std::cin >> langQuantity;
        for (int j = 0; j < langQuantity; ++j)
        {
            std::string bufString;
            std::cin >> bufString;
            ++langMap[bufString];
        }
    }

    //определяем общеизвестные и уникальные языки и их количество по словарю языков
    std::tuple<int, int, std::vector<std::string>, std::vector<std::string>> result = discoverLangKnowledge(studentsQuantity, langMap);

    //вывод количества общеизвестных языков и их перечисление
    std::cout << std::get<0>(result) << std::endl;
    for (auto commLangs : std::get<2>(result))
    {
        std::cout << commLangs << std::endl;
    }
    // вывод количества уникальных языков и их перечисление
    std::cout << std::get<1>(result) << std::endl;
    for (auto uniqueLangs : std::get<3>(result))
    {
        std::cout << uniqueLangs << std::endl;
    }

    return 0;
}