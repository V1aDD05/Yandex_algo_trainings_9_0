#include <iostream>
#include <utility>  //std::pair
#include <map>

/*
Сложность по времени: O(N*logN), N - количество входных команд
Сложность по памяти: O(M) = O(N), M <= N - количество уникальных клеток.
*/

int main()
{
    //словарь закрашенных клеток 
    //(ключ - координаты, значение - колличество закрашиваний)
    std::map<std::pair<int, int>, int> ceilMap;

    //координата 'X' (движение по горизонтали)
    int xCoord = 0;

    //координата 'Y' (движение по вертикали)
    int yCoord = 0;

    //робот закрашивает начальную клетку по условию
    ceilMap[{xCoord, yCoord}] = 1;

    //счётчик клеток, закрашенных более 1 раза
    int counter = 0;

    char bufChar;
    while (std::cin.get(bufChar) && bufChar != '\n')
    {
        if (bufChar == 'U')
        {
            ++yCoord;
        }
        else if (bufChar == 'L')
        {
            --xCoord;
        }
        else if (bufChar == 'D')
        {
            --yCoord;
        }
        else if (bufChar == 'R')
        {
            ++xCoord;
        }

        ++ceilMap[{xCoord, yCoord}];
        if (ceilMap[{xCoord, yCoord}] == 2)
        {
            ++counter;
        }
    }
    std::cout << counter << std::endl;

    return 0;
}