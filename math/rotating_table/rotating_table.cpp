#include <iostream>
#include <vector>

/*
Сложность по времени: O(n).
Сложность по памяти: O(n)
*/


int findMinShift(const std::vector<int> &initialPlacement)
{
    size_t n = initialPlacement.size();
    std::vector<bool> goodShifts(n, true);

    // идея: блюдо для i-го гостя расположено на позиции initialPlacement[i],
    // значит, стол нельзя поворачивать на shift = initialPlacement[i] - i (если shift > 0) позиций,
    // либо на shift = initialPlacement[i] - i + n позиций.
    //проходим по всем блюдам, блокируем непдходящие смещения
    for (int i = 0; i < n; ++i) {
        int shift = initialPlacement[i] - i;
        if (shift < 0) {
            shift += n;
        }
        goodShifts[shift] = false;
    }

    //ищем наименьшеешее подходящее смещение
    int minShift = -1;
    for (int i = 0; i < n; ++i)
    {
        if (goodShifts[i] == true) {
            minShift = i;
            break;
        }
    }

    return minShift;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> initialPlacement;
    initialPlacement.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        initialPlacement.push_back(bufInt - 1);
    }

    std::cout << findMinShift(initialPlacement) << std::endl;

    return 0;
}