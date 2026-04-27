#include <iostream>
#include <algorithm>
#include <tuple>

void chooseSides(const int p, const int v, const int q, const int m, std::pair<int, int> &right, std::pair<int, int> &left)
{
    // если дерево p Васи правее дерева q Маши
    if (p >= q)
    {
        left = {q, m};
        right = {p, v};
    }

    // наоборот
    else
    {
        left = {p, v};
        right = {q, m};
    }
}

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

    //пара "координата центрального дерева - радиус"
    std::pair<int,int> right, left;

    //формирование пар в зависимости от расположения центральных деревьев
    chooseSides(p, v, q, m, right, left);

    //вывод количества покрашенных деревьев
    std::cout << countColoured(right, left) << std::endl;

    return 0;
}