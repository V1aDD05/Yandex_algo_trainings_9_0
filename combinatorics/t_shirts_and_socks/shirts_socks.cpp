#include <iostream>
#include <algorithm>    //max
#include <utility>      //pair
#include <vector>
#include <climits>      //INT_MAX

std::pair<int, int> minimalCombination(const int blueShirts, const int redShirts, const int blueSocks, const int redSocks)
{
    std::pair<int, int> result;
    std::vector<std::pair<int, int>> cases;

    // считаем, сколько нужно вынуть, чтобы достать красную пару
    // если чего-то синего ноль, то этот вариант нет смысла рассматривать
    if (blueShirts > 0 && blueSocks > 0)
    {
        cases.push_back({redShirts + 1, redSocks + 1});
    }
    // считаем, сколько нужно вынуть, чтобы достать синюю пару
    if (redShirts > 0 && redSocks > 0)
    {
        cases.push_back({blueShirts + 1, blueSocks + 1});
    }
    // если всех элементов не ноль, надо ещё проанализировать случаи
    //(если чего-то ноль, то придём к случаям выше):
    if (blueShirts > 0 && redShirts > 0 && blueSocks > 0 && redSocks > 0)
    {
        // считаем, сколько нужно вынуть пар носков, чтобы подошла любая (первая) майка
        cases.push_back({1, std::max(blueSocks, redSocks) + 1});
        // считаем, сколько нужно вынуть маек, чтобы подошла любая (первая) пара носков
        cases.push_back({std::max(blueShirts, redShirts) + 1, 1});
    }

    int minSum = INT_MAX;
    
    for (auto combination : cases)
    {
        int combSum = combination.first + combination.second;
        if (combSum < minSum)
        {
            minSum = combSum;
            result.first = combination.first;
            result.second = combination.second;
        }
    }

    return result;
}

int main()
{
    int blueShirts, redShirts, blueSocks, redSocks;
    std::cin >> blueShirts >> redShirts >> blueSocks >> redSocks;

    std::pair<int, int> result = minimalCombination(blueShirts, redShirts, blueSocks, redSocks);

    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}
