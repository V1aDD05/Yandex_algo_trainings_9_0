#include <iostream>
#include <fstream>
#include <initializer_list>
#include <vector>
#include <cmath>

using namespace std;

int wrap(vector<int> buildings)
{   
    /*
    Можно было делать не вложенный цикл с временной сложностью O(n),
    а сделать два прохода - O(n): идём вправо, ищем расстояние от 
    жилого здания до магазина слева. Затем идём влево, ищем расстояние
    от жилого здания до магазина справа

    Также можно было выбор минимума и максимума делать через min(), max()
    */

    vector<int> shopsLocation;
    size_t bulildingsSize = buildings.size();

    for (size_t i = 0; i < bulildingsSize; ++i)
    {
        if (buildings[i] == 2)
        {
            shopsLocation.push_back(static_cast<int>(i));
        }
    }

    int maxDist = 1;
    for (size_t i = 0; i < bulildingsSize; ++i)
    {
        if (buildings[i] == 1)
        {
            int minDist = 10;
            for (auto shop : shopsLocation)
            {
                int buf = abs(static_cast<int>(i) - shop);
                if (minDist > buf)
                {
                    minDist = buf;
                }
            }
            if (maxDist < minDist)
            {
                maxDist = minDist;
            }
        }
    }

    return maxDist;
}

int main()
{
    ifstream inputFile("input.txt");

    int bufInt;
    vector<int> buildings;

    while (inputFile >> bufInt)
    {
        buildings.push_back(bufInt);
    }

    int maxDist = wrap(buildings);

    cout << maxDist << endl;

    return 0;
}