#include <iostream>
#include <vector>
#include <utility>  //std::pair
#include <climits>  //INT_MAX

/*
Сложность по времени: O(n), n - суммарное количество чисел в двух наборах
Сложность по памяти: O(n)
*/

// функция формирования вектора с значениями цветов маек и брюк
std::vector<int> formVecOfItems(const int t)
{
    std::vector<int> items;
    items.reserve(t);

    for (int i = 0; i < t; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        items.push_back(bufInt);
    }

    return items;
}

// функция поиска пары из наиболее подходящих друг другу майки и брюк
std::pair<int, int> findClosestPair(const std::vector<int> &tShirts, const std::vector<int> &trousers)
{
    const int n = static_cast<int>(tShirts.size());
    const int m = static_cast<int>(trousers.size());
    int k = n + m;

    int minAbs = INT_MAX;

    // пара наиболее подходящих друг другу маек и брюк
    std::pair<int, int> closestPair;

    //"указатели" текущей рассматриваемой майки и
    // текущих рассматриваемых брюк в соответствующих векторах
    int tShirtsPtr = 0;
    int trousersPtr = 0;

    for (int i = 0; i < k - 1; ++i)
    {
        int tShirtsTemp = tShirts[tShirtsPtr];
        int trousersTemp = trousers[trousersPtr];

        int absTemp = abs(tShirtsTemp - trousersTemp);

        // проверяем, насколько текущие значения подходят друг к другу
        // если лучше, чем выделенные ранее - записываем их
        // в возвращаемую из функции пару
        if (absTemp < minAbs)
        {
            minAbs = absTemp;
            closestPair.first = tShirtsTemp;
            closestPair.second = trousersTemp;
        }

        // меньше нуля различие быть не может, по условию
        // выводим любую пару с минимальным различием -> дальше можно не перебирать
        if (!minAbs)
        {
            break;
        }

        // сдвигаемся по вектору брюк, если майки прошли до конца
        // или если текущий элемент брюк меньше текущего элемента маек
        if (tShirtsPtr == n - 1 || (tShirtsTemp > trousersTemp && trousersPtr < m - 1))
        {
            ++trousersPtr;
        }
        // во всех остальных случаях двигаемся по майкам
        else
        {
            ++tShirtsPtr;
        }
    }

    return closestPair;
}


int main()
{
    // считываем количество маек
    int n;
    std::cin >> n;

    // формируем вектор цветов маек
    std::vector<int> tShirts = formVecOfItems(n);

    // считываем количество брюк
    int m;
    std::cin >> m;

    // формируем вектор цветов брюк
    std::vector<int> trousers = formVecOfItems(m);

    //ищем пару из наиболее подходящих друг другу майки и брюк
    std::pair<int, int> closestPair = findClosestPair(tShirts, trousers);

    std::cout << closestPair.first << " " << closestPair.second << std::endl;

    return 0;
}