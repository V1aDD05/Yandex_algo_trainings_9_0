#include <iostream>
#include <utility>
#include <stack>
#include <vector>

/*
Метод - стек рекордов
Сложность по времени: O(n).
Сложность по памяти: O(n)
*/

std::vector<int> relocation(const int n)
{
    //вектор, хранящий информацию о переселении
    std::vector<int> towns;
    towns.reserve(n);

    //стек рекордов
    std::stack<std::pair<int, int>> townStack;

    for (int i = 0; i < n; ++i)
    {
        int bufCost;
        std::cin >> bufCost;

        //если жители нигде не остановятся, выводим '-1'
        towns.push_back(-1);
        while (!townStack.empty() && townStack.top().first > bufCost)
        {
            int bufIndex = townStack.top().second;
            towns[bufIndex] = i;
            townStack.pop();
        }
        townStack.push({bufCost, i});
    }

    return towns;
}

int main()
{
    int n;
    std::cin >> n;

    // вектор, хранящий информацию о переселении
    std::vector<int> towns = relocation(n);

    bool isFirst = true;
    for (const auto &town : towns)
    {
        if (isFirst)
        {
            isFirst = false;
            std::cout << town;
        }
        else
        {
            std::cout << ' ' << town;
        }
    }
    std::cout << std::endl;

    return 0;
}