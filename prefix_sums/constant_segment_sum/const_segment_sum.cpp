#include <iostream>
#include <utility>      //std::pair
#include <algorithm>    //std::min, std::max
#include <vector>

/*
Сложность по времени: O(N + Q), Q - количество запросов
Сложность по памяти: O(N).
*/

// функция формирования префиксных сумм
std::vector<long long int> fillPrefixSums(const int n)
{
    // запросов будет много, поэтому будем хранить префиксные суммы
    std::vector<long long int> sums;
    sums.reserve(n + 1);
    sums.push_back(0);

    // формируем вектор префиксных сумм по входным данным
    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        sums.push_back(sums[i] + bufInt);
    }
    return sums;
}

//функция обработки запросов по определению сумм элементов
//и вычисления результирующей суммы
long long int countSum(const int q, const int x0, const std::vector<long long int> &sums)
{
    // сумма всех запросов
    long long int requestSum = 0;

    int n = static_cast<int>(sums.size()) - 1;

    // числа из последовательности для первой итерации
    std::pair<int, int> xs;
    xs.first = x0;
    xs.second = (static_cast<long long int>(x0) * 11173 + 1) % 1000000007;

    for (int i = 0; i < q; ++i)
    {
        int L = std::min(xs.first % n, xs.second % n);
        int R = std::max(xs.first % n, xs.second % n);

        requestSum += sums[R + 1] - sums[L];

        // числа из последовательности для следующей итерации
        xs.first = (static_cast<long long int>(xs.second) * 11173 + 1) % 1000000007;
        xs.second = (static_cast<long long int>(xs.first) * 11173 + 1) % 1000000007;
    }

    return requestSum;
}

int main()
{
    int n;
    std::cin >> n;

    // запросов будет много, поэтому будем хранить префиксные суммы
    std::vector<long long int> sums = fillPrefixSums(n);

    //считываем количество запросов и
    //начальное значение генератора случайных чисел
    int q, x0;
    std::cin >> q >> x0;

    //выводим результат обработки запросов
    std::cout << countSum(q,x0,sums) % 1000000007 << std::endl;

    return 0;
}