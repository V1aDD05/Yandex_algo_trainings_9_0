#include <iostream>
#include <map>
#include <stack>
#include <queue>

/*
Сложность по времени: O(N*logN)
Сложность по памяти: O(N)
*/

bool defineAbility(std::queue<int> &firstLine, std::map<int, bool> &vagonMap)
{
    std::stack<int> deadEnd;

    bool ability = true;

    // пользуемся тем, что вагоны в map отсортированы по возрастанию
    for (auto &vagon : vagonMap)
    {
        // случай, когда младший необработанный вагон в тупике
        if (vagon.second == true)
        {
            // если самый младший необработанный вагон в тупике сверху,
            //  то ок
            // проверка на deadEnd.empty() не требуется: есть vagon.second == true
            if (deadEnd.top() == vagon.first)
            {
                deadEnd.pop();
                vagonMap[vagon.first] = false;
            }
            // если он не сверху, в нужном порядке выставить не получится
            else
            {
                ability = false;
                break;
            }
        }
        // случай, когда младший необработанный вагон на первом пути
        else
        {
            // загоняем вагоны в тупик, пока младший необработанный
            // не окажется наверху
            while (vagon.second == false)
            {
                vagonMap[firstLine.front()] = true;
                deadEnd.push(firstLine.front());
                // проверка на firstLine.empty() в данном случае не требуется
                firstLine.pop();
            }
            // проверка на deadEnd.empty() в данном случае не требуется
            deadEnd.pop();

            vagonMap[vagon.first] = false;
        }
    }
    return ability;
}

int main()
{
    int n;
    std::cin >> n;

    // словарьЮ хранящий информацию о вагонах в тупике
    //  true - вагон в тупике, false - нет
    std::map<int, bool> vagonMap;

    // очередь, хранящая информацию о вагонах на первом (исходном) пути
    std::queue<int> firstLine;

    // первичное заполнение информации
    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        // обозначаем, что вагоны не в тупике
        vagonMap[bufInt] = false;
        firstLine.push(bufInt);
    }

    // определяем, возможно ли расположить вагоны на пути 2 нужным образом
    bool ability = defineAbility(firstLine, vagonMap);

    if (ability)
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}