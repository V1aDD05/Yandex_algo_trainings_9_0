#include <iostream>
#include <sstream>      //std::istringstream
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>    //std::sort

/*
Сложность по времени: O(N*logN) (за счёт сортировки)
Сложность по памяти: O(2*N) = O(N).
*/

// функция формирования множества уникальных чисел первого набора
std::unordered_set<int> fillFirstSet(const std::string &bufLine)
{
    //множество уникальных чисел первого набора
    std::unordered_set<int> first;

    //ранее считанная строка
    std::istringstream iss(bufLine);

    // формирование множества уникальных чисел первого набора
    int bufInt;
    while (iss >> bufInt)
    {
        auto it = first.find(bufInt);
        if (it == first.end())
        {
            first.insert(bufInt);
        }
    }

    return first;
}

// функция формирования пресечения наборов
std::vector<int> findIntersection(const std::string &bufLine, const std::unordered_set<int> &first)
{
    // множество уникальных чисел второго набора
    std::unordered_set<int> second;

    // ранее считанная строка
    std::istringstream iss(bufLine);

    //вектор, в котором будет храниться пересечение (пока что не отсортированное)
    std::vector<int> intersection;

    // выделение пересечения двух наборов
    int bufInt;
    while (iss >> bufInt)
    {
        // т.к. считываем числа второго набора, то достаточно проверить,
        // есть ли эти числа в первом для обнаружения пересечения
        auto it = first.find(bufInt);
        if (it != first.end())
        {
            auto itSecond = second.find(bufInt);
            if (itSecond == second.end())
            {
                intersection.push_back(bufInt);
                second.insert(bufInt);
            }
        }
    }

    return intersection;
}

int main()
{

    std::string bufLine;
    getline(std::cin, bufLine);     //считывание первой строки (набора)

    // формирование множества уникальных чисел первого набора
    std::unordered_set<int> first = fillFirstSet(bufLine);

    getline(std::cin, bufLine); // считывание второй строки (набора)

    // формирование пресечения наборов
    std::vector<int> intersection = findIntersection(bufLine, first);
    
    //сортируем вектор пересечения
    auto vecBegin = intersection.begin();
    auto vecEnd = intersection.end();
    std::sort(vecBegin, vecEnd);            //O(N*logN)

    bool isFirst = true;
    for (auto member : intersection)
    {
        if (!isFirst) {
            std::cout << " ";
        }
        isFirst = false;
        std::cout << member;
    }
    std::cout << std::endl;

    return 0;
}