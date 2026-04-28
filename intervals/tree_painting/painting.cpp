#include <iostream>
#include <algorithm>
#include <tuple>

/*
Сложность по времени: O(1)
Сложность по памяти: O(1).
*/

struct ColourParams
{
    int centerVasya;
    int radiusVasya;
    int centerMary;
    int radiusMary;
};

// функция формирования пар в зависимости от расположения центральных деревьев
void chooseSides(const ColourParams &params, std::pair<int, int> &right, std::pair<int, int> &left)
{
    // если дерево p Васи правее дерева q Маши
    if (params.centerVasya >= params.centerMary)
    {
        left = {params.centerMary, params.radiusMary};
        right = {params.centerVasya, params.radiusVasya};
    }

    // наоборот
    else
    {
        left = {params.centerVasya, params.radiusVasya};
        right = {params.centerMary, params.radiusMary};
    }
}

//функция подсчёта закрашенных деревьев
int countColoured(const std::pair<int, int> &right, const std::pair<int, int> &left)
{
    int result;
    // случай 1: нет зоны пересечения
    if ((right.first - left.first) > (right.second + left.second + 1))
    {
        result = 2 * (right.second + left.second + 1);
    }

    // случай 2: есть пересечение либо касание
    else
    {
        int rightBound = std::max(right.first + right.second, left.first + left.second);
        int leftBound = std::min(right.first - right.second, left.first - left.second);
        result = rightBound - leftBound + 1;
    }
    return result;
}

int main()
{

    int p, v, q, m;
    std::cin >> p >> v >> q >> m;

    //структура, хранящая входные параметры
    ColourParams params = {p, v, q, m};

    //пара "координата центрального дерева - радиус"
    std::pair<int,int> right, left;

    //формирование пар в зависимости от расположения центральных деревьев
    chooseSides(params, right, left);

    //вывод количества покрашенных деревьев
    std::cout << countColoured(right, left) << std::endl;

    return 0;
}