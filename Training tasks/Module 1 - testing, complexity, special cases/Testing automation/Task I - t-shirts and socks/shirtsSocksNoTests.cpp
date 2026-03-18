#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

pair<int, int> wrap(const int blueShirts, const int redShirts, const int blueSocks, const int redSocks)
{
    pair<int, int> result;
    vector<pair<int, int>> cases;

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
        cases.push_back({1, max(blueSocks, redSocks) + 1});
        // считаем, сколько нужно вынуть маек, чтобы подошла любая (первая) пара носков
        cases.push_back({max(blueShirts, redShirts) + 1, 1});
    }

    int minSum = 2000000003;
    int combSum;
    for (auto combination : cases)
    {
        combSum = combination.first + combination.second;
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
    ifstream inputFile("input.txt");
    int blueShirts, redShirts, blueSocks, redSocks;
    inputFile >> blueShirts >> redShirts >> blueSocks >> redSocks;

    pair<int, int> result = wrap(blueShirts, redShirts, blueSocks, redSocks);

    cout << result.first << " " << result.second << endl;

    return 0;
}
