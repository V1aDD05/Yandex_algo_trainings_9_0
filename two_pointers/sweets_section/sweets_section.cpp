#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>        //std::max


/*
Сложность по времени: O(n), n - суммарное количество конфет
Сложность по памяти: O(n).
*/

//функция формирования вектора "конфет"
std::vector<int> fillSweetsVec(const int n)
{
    std::vector<int> sweetsType;
    sweetsType.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        sweetsType.push_back(bufInt);
    }
    return sweetsType;
}

// функция поиска максимальной длины "конфетного подотрезка"
int maxSweetsQuantity(const std::vector<int> &sweetsType)
{
    // словарь, хранящий количество конфет того или иного типа
    // в "конфетном подотрезке"
    std::unordered_map<int, int> cookiesMap;

    //возвращаемый параметр - максимальная длина "конфетного подотрезка"
    int maxLen = 0;

    //"указатели" левой и правой границы конфетного подотрезка
    size_t left = 0;
    size_t right = 0;

    size_t n = sweetsType.size();
    while (right < n)
    {
        //двигаем правую границу подотрезка вправо,
        //пока количество типов конфет не более 2.
        //Пока типов ровно 2, запоминаем длину подотрезка
        ++cookiesMap[sweetsType[right]];
        size_t mapSize = cookiesMap.size();
        if (mapSize == 2)
        {
            int bufLen = right - left + 1;
            maxLen = std::max(maxLen, bufLen);
        }
        else if (mapSize > 2)
        {
            //если типов стало больше 2, двигаем левую границу вправо,
            //пока типов не станет 2
            while (cookiesMap.size() > 2)
            {
                --cookiesMap[sweetsType[left]];
                if (cookiesMap[sweetsType[left]] == 0)
                {
                    cookiesMap.erase(sweetsType[left]);
                }
                ++left;
            }
        }
        ++right;
    }

    return maxLen;
}


int main()
{
    //считываем количество конфет
    int n;
    std::cin >> n;

    //формируем вектор конфет
    std::vector<int> sweetsType = fillSweetsVec(n);

    // выводим максимальную длину "конфетного подотрезка"
    std::cout << maxSweetsQuantity(sweetsType) << std::endl;

    return 0;
}