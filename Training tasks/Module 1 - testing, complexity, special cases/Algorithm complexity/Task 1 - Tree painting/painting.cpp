#include <iostream>
#include <algorithm>
#include <tuple>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::get;
    using std::make_tuple;
    using std::max;
    using std::min;
    using std::tuple;

    int p, v, q, m, result;
    cin >> p >> v;

    cin >> q >> m;

    // если дерево p Васи правее дерева q Маши
    tuple<int, int, int, int> right, left;

    if (p >= q)
    {
        left = make_tuple(q, m, q - m, q + m);
        right = make_tuple(p, v, p - v, p + v);
    }

    // наоборот
    else
    {
        left = make_tuple(p, v, p - v, p + v);
        right = make_tuple(q, m, q - m, q + m);
    }

    // случай 1: нет зоны пересечения
    if ((get<0>(right) - get<0>(left)) > (get<1>(right) + get<1>(left) + 1))
    {
        result = 2 * (get<1>(right) + get<1>(left) + 1);
    }

    // случай 2: есть пересечение либо касание
    else
    {
        int rightBound = max(get<3>(right), get<3>(left));
        int leftBound = min(get<2>(right), get<2>(left));
        result = rightBound - leftBound + 1;
    }
    cout << result << endl;

    return 0;
}