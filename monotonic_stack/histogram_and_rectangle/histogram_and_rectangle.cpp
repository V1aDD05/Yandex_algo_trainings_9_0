#include <iostream>
#include <utility>      //std::pair
#include <algorithm>    //std::max
#include <tuple>
#include <vector>
#include <stack>


void lessNeighbours(std::vector<std::tuple<int, int, int>> &histVec)
{
    size_t vecSize = histVec.size();

    //стек рекордов
    std::stack<std::pair<int, int>> histStack;

    //проход слева направо
    for (size_t i = 0; i < vecSize; ++i)
    {
        int histHeight = std::get<0>(histVec[i]);
        while (!histStack.empty() && histStack.top().first > histHeight)
        {
            int index = histStack.top().second;
            histStack.pop();
            std::get<1>(histVec[index]) = i;
        }
        histStack.push({histHeight, i});
    }

    //очистка стека
    while (!histStack.empty())
    {
        histStack.pop();
    }

    //проход справа налево
    for (size_t i = vecSize; i-- > 0; )
    {
        int histHeight = std::get<0>(histVec[i]);
        while (!histStack.empty() && histStack.top().first > histHeight)
        {
            int index = histStack.top().second;
            histStack.pop();
            std::get<2>(histVec[index]) = i;
        }
        histStack.push({histHeight, i});
    }
}

long long int maxSquare(const std::vector<std::tuple<int, int, int>> &histVec)
{
    long long int maxSquare = 0;
    size_t vecSize = histVec.size();
    for (size_t i = 0; i < vecSize; ++i)
    {
        long long int bufSquare = static_cast<long long int>(std::get<0>(histVec[i])) * (std::get<1>(histVec[i]) - std::get<2>(histVec[i]) - 1);
        maxSquare = std::max(maxSquare, bufSquare);
    }
    return maxSquare;
}


int main()
{
    int vecSize;
    std::cin >> vecSize;

    //первое поле - высота столбца, второе - ближайший меньший справа,
    // третье - ближайший меньший слева
    std::vector<std::tuple<int, int, int>> histVec;
    histVec.reserve(vecSize);

    for (int i = 0; i < vecSize; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        //по умолчанию ближайшие меньшие для всех элементов за пределеами массива
        histVec.push_back({bufInt, vecSize, -1});
    }

    lessNeighbours(histVec);

    std::cout << maxSquare(histVec) << std::endl;

    return 0;
}