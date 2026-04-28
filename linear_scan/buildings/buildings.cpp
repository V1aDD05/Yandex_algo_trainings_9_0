#include <iostream>
#include <vector>
#include <algorithm>    //std::max, std::min
#include <queue>
#include <climits>      //INT_MAX

/*
Сложность по времени: O(n), n - количество зданий
Сложность по памяти: O(n).
*/

// функция заполнения информации о зданиях 
// и подсчёта жилых домов
std::vector<int> fillBuildings(int &housesNumber)
{
    std::vector<int> buildings;

    int bufInt;
    while (std::cin >> bufInt)
    {
        buildings.push_back(bufInt);
        if (bufInt == 1)
        {
            ++housesNumber;
        }
    }

    return buildings;
}

// функция определения наибольшего расстояния от дома до
// ближайшего к нему магазина
int findMaxDist(const std::vector<int>& buildings, const int housesNumber)
{   
    

    size_t bulildingsSize = buildings.size();
    std::vector<std::vector<int>> distances(housesNumber, std::vector<int>(2, INT_MAX));
    std::queue<int> distQueue;

    // проход слева направо
    int pushedFromQueue = 0;
    for (size_t i = 0; i < bulildingsSize; ++i) {
        if (buildings[i] == 1) {
            distQueue.push(i);
        }
        else if (buildings[i] == 2) {
            while (!distQueue.empty())
            {
                distances[pushedFromQueue][0] = i - distQueue.front();
                distQueue.pop();
                ++pushedFromQueue;
            }
        }
    }
    //очистка стека
    while (!distQueue.empty())
    {
        distQueue.pop();
    }

    //проход справа налево
    pushedFromQueue = 0;
    for (size_t i = bulildingsSize; i-- > 0; )
    {
        if (buildings[i] == 1) {
            distQueue.push(i);
        }
        else if (buildings[i] == 2)
        {
            while (!distQueue.empty())
            {
                distances[housesNumber - pushedFromQueue - 1][1] = distQueue.front() - i;
                distQueue.pop();
                ++pushedFromQueue;
            }
        }
    }

    int maxDist = 0;

    //ищем максимальное расстояние
    for (int i = 0; i < housesNumber; ++i)
    {
        maxDist = std::max(maxDist, std::min(distances[i][0], distances[i][1]));
    }

    return maxDist;
}

int main()
{
    // будем считать количество жилых домов,
    // чтобы вектор расстояний сделать размером с количество жилых домов
    int housesNumber = 0;

    //заполняем информацию о зданиях,
    //считаем количество жилых домов
    std::vector<int> buildings = fillBuildings(housesNumber);

    //определяем и выводим наибольшее расстояние от дома до
    //ближайшего к нему магазина
    std::cout << findMaxDist(buildings, housesNumber) << std::endl;

    return 0;
}