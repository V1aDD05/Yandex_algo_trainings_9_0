#include <iostream>
#include <algorithm>    //std::min

int minFold(const long long int n, const long long int m, const long long int h, const long long int w)
{
    /*
    важное замечание: складывания в двух различных направлениях независимы,
    поэтому результирующее количество складываний есть сумма складываний по двум осям
    */

    //подсчёт количества складываний в исходном положении
    long long int counter = 0;
    long long int initialH = h;
    long long int initialW = w;

    while (initialH < n) {
        ++counter;
        initialH *= 2;
    }

    while (initialW < m) {
        ++counter;
        initialW *= 2;
    }

    // подсчёт количества складываний при повороте простыни на 90 градусов

    long long int rotatedCounter = 0;
    long long int rotatedH = h;
    long long int rotatedW = w;

    while (rotatedH < m)
    {
        ++rotatedCounter;
        rotatedH *= 2;
    }

    while (rotatedW < n)
    {
        ++rotatedCounter;
        rotatedW *= 2;
    }

    //возвращаем меньшее количество складываний
    return std::min(counter, rotatedCounter);
}

int main()
{
    /*
    Сложность по времени: O(log n + log m) = O(log(n*m))
    Сложность по памяти: O(1)
    */
    long long int n, m, h, w;

    std::cin >> n >> m >> h >> w;

    long long int result = minFold(n, m, h, w);

    std::cout << result << std::endl;

    return 0;
}