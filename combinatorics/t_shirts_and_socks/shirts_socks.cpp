#include <iostream>
#include <algorithm>    //std::max
#include <utility>      //std::pair
#include <vector>
#include <climits>      //INT_MAX

/*
Сложность по времени: O(1),
Сложность по памяти: O(1)
*/

//структура, хранящая количество предметов одежды синего и красного цвета
struct Clothes
{
    int blueShirts;
    int redShirts;
    int blueSocks;
    int redSocks;
};

// функция определения минимального суммарного количества вытащенной одежды
std::pair<int, int> minimalCombination(const Clothes &clothesItems)
{
    std::pair<int, int> result;
    std::vector<std::pair<int, int>> cases;

    // считаем, сколько нужно вынуть, чтобы достать красную пару
    // если чего-то синего ноль, то этот вариант нет смысла рассматривать
    if (clothesItems.blueShirts > 0 && clothesItems.blueSocks > 0)
    {
        cases.push_back({clothesItems.redShirts + 1, clothesItems.redSocks + 1});
    }
    // считаем, сколько нужно вынуть, чтобы достать синюю пару
    if (clothesItems.redShirts > 0 && clothesItems.redSocks > 0)
    {
        cases.push_back({clothesItems.blueShirts + 1, clothesItems.blueSocks + 1});
    }
    // если всех элементов не ноль, надо ещё проанализировать случаи
    //(если чего-то ноль, то придём к случаям выше):
    if (clothesItems.blueShirts > 0 && clothesItems.redShirts > 0 && clothesItems.blueSocks > 0 && clothesItems.redSocks > 0)
    {
        // считаем, сколько нужно вынуть пар носков, чтобы подошла любая (первая) майка
        cases.push_back({1, std::max(clothesItems.blueSocks, clothesItems.redSocks) + 1});
        // считаем, сколько нужно вынуть маек, чтобы подошла любая (первая) пара носков
        cases.push_back({std::max(clothesItems.blueShirts, clothesItems.redShirts) + 1, 1});
    }

    int minSum = INT_MAX;
    
    for (const auto &combination : cases)
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
    //считываем количества маек и носков каждого из цветов
    int blueShirts, redShirts, blueSocks, redSocks;
    std::cin >> blueShirts >> redShirts >> blueSocks >> redSocks;

    Clothes clothesItems = {blueShirts, redShirts, blueSocks, redSocks};

    // определяем минимальное суммарное количество вытащенной одежды
    std::pair<int, int> result = minimalCombination(clothesItems);

    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}
