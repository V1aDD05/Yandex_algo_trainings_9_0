#include <iostream>     
#include <vector>       
#include <utility>      //std::pair
#include <algorithm>    //std::max, std::min

/*
Сложность по времени: O(n), n - количество базовых станций
Сложность по памяти: O(n).
*/

// функция заполнения вектора сигналов от базовых станций
std::vector<std::pair<int, int>> fillSignals(const int n)
{
    std::vector<std::pair<int, int>> signals;
    signals.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int xi, di;
        std::cin >> xi >> di;
        signals.push_back({xi - di, xi + di});
    }
    return signals;
}

// функция определения промежутка, на котором может быть расположен робот
int findIntersection(const std::vector<std::pair<int, int>>& signals, const int n)
{
    //промежуток возможных положений робота
    std::pair<int, int> intersection = signals[0];

    //обрабатываем все сигналы базовых станций
    for (int i = 1; i < n; ++i) {
        std::pair<int, int> bufPair;
        bufPair = signals[i];

        // определяем пересечение промежутка возможных положений робота
        // и промежутка показаний i-ой базовой станции
        int moreLeft = std::max(intersection.first, bufPair.first);
        int lessRight = std::min(intersection.second, bufPair.second);

        if (moreLeft > lessRight) {
            intersection.second = -1;
            break;
        }
        else if (moreLeft == lessRight) {
            intersection.first = moreLeft;
            intersection.second = moreLeft;
        }
        else if (moreLeft < lessRight) {
            intersection.first = moreLeft;
            intersection.second = lessRight;
        }
    }

    return intersection.second;
}

int main()
{
    //считываем количество базовых станций
    int n;
    std::cin >> n;

    //заполняем вектор сигналов от базовых станций
    std::vector<std::pair<int, int>> signals = fillSignals(n);

    //определяем промежуток, на котором может быть расположен робот
    std::cout << findIntersection(signals, n) << std::endl;

    return 0;
}