#include<iostream>
#include <vector>

/*
Сложность по времени: O(3*N) = O(N)
Сложность по памяти: O(3*N) = O(N).
*/

//функция вычисления суммы тройных произведений
long long int tripleMulSums(const int n, const int mod, const std::vector<int> &integers, const std::vector<long long int> &prefSums, const std::vector<long long int> suffSums)
{
    int rightBound = n - 1;
    // непосредтвенно подсчёт сумм как prefSums[j] * aj * suffSums[j + 1]
    long long int sum = 0;
    for (int j = 1; j < rightBound; ++j)
    {
        //дважды беру остаток от деления во избежание переполнения
        long long int mul = (((static_cast<long long int>(prefSums[j]) * integers[j]) % mod) * suffSums[j + 1]) % mod;
        sum = (sum + mul) % mod;
    }

    return sum;
}

// функция записи вектора чисел, вычисления префиксных сумм и записи их в вектор
std::vector<long long int> countPrefSums(const int n, const int mod, std::vector<int> &integers)
{
    //вектор префиксных сумм
    std::vector<long long int> prefSums;
    prefSums.reserve(n + 1);
    prefSums.push_back(0);

    // формирование вектора чисел и
    // вычисление вектора префиксных сумм
    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        integers.push_back(bufInt);

        prefSums.push_back((prefSums[i] + bufInt) % mod);
    }

    return prefSums;
}

// функция вычисления суффиксных сумм и записи их в вектор
std::vector<long long int> countSuffSums(const int n, const int mod, const std::vector<int> &integers)
{
    std::vector<long long int> suffSums(n + 1);

    suffSums[n] = 0;

    // вычисление вектора суффиксных сумм
    int rightBound = n - 1;
    for (int i = rightBound; i >= 0; --i)
    {
        int bufInt = integers[i];
        // использовать insert() нельзя - O(n^2)
        suffSums[i] = (suffSums[i + 1] + bufInt) % mod;
    }

    return suffSums;
}

int main()
{
    //количество чисел в последовательности
    int n;
    std::cin >> n;

    // вектор чисел
    // (для подсчёта суффиксных сумм)
    std::vector<int> integers;
    integers.reserve(n);

    int mod = 1000000007;

    // заполняем вектор чисел, вычисляем вектор префиксных сумм
    std::vector<long long int> prefSums = countPrefSums(n, mod, integers);

    // вычисляем вектор суффиксных сумм
    std::vector<long long int> suffSums = countSuffSums(n, mod, integers);

    //вычисляем и выводим сумму тройных произведений
    std::cout << tripleMulSums(n, mod, integers, prefSums, suffSums) << std::endl;

    return 0;
}