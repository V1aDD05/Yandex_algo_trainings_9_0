#include <iostream>
#include <utility> //std::pair
#include <stack>
#include <vector>

/*
Метод - стек рекордов
Сложность по времени: O(n).
Сложность по памяти: O(n)
*/

// функция вывода информации о том, из какого города в какой будут переселяться
void outputRelocationTown(const std::vector<int> &towns)
{
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
}

//функция определения, из какого города в какой будут переселяться
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
    //считываем количество городов
    int n;
    std::cin >> n;

    // создаём и заполняем вектор, хранящий информацию о переселении
    std::vector<int> towns = relocation(n);

    //выводим информацию о том, куда из какого города переселились
    outputRelocationTown(towns);

    return 0;
}