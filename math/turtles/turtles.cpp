#include <iostream>
#include <unordered_set>

/*
Сложность по времени: O(n).
Сложность по памяти: O(n)
*/

int main()
{
    int turtlesQuantity;
    std::cin >> turtlesQuantity;

    // будем хранить в множестве значения ai
    std::unordered_set<int> turtlesOrder;
    auto it = turtlesOrder.begin();

    for (int i = 0; i < turtlesQuantity; ++i)
    {
        int ai, bi;
        std::cin >> ai >> bi;
        // проверяем, что числа неотрицательные и в сумме дают количество минус одна (текущая) черепаха
        if (ai >= 0 && bi >= 0 && (ai + bi) == (turtlesQuantity - 1))
        {
            it = turtlesOrder.find(ai);
            // сохраняем только те ai, которых ещё не было
            //(две черепахи не могут быть на одном месте)
            if (it == turtlesOrder.end())
            {
                turtlesOrder.insert(ai);
            }
        }
    }

    std::cout << turtlesOrder.size() << std::endl;

    return 0;
}