#include <iostream>
#include <vector>
#include <algorithm>    //std::max, std::min
#include <queue>
#include <climits>      //INT_MAX

int findMaxDist(const std::vector<int>& buildings, const int housesNumber)
{   
    /*
    Сложность по времени: O(n).
    Сложность по памяти: O(n + k) = O(n), где k - количество жилых домов
    */

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
    
    std::vector<int> buildings;

    //будем считать количество жилых домов,
    //чтобы вектор расстояний сделать размером с количество жилых домов
    int housesNumber = 0;

    int bufInt;
    while (std::cin >> bufInt)
    {
        buildings.push_back(bufInt);
        if (bufInt == 1)
        {
            ++housesNumber;
        }
    }

    std::cout << findMaxDist(buildings, housesNumber) << std::endl;

    return 0;
}