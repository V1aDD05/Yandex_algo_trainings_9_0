#include <iostream>
#include <string>
#include <vector>
#include <utility>  //std::pair
#include <unordered_map>
#include <climits> //INT_MAX

/*
Сложность по времени: O(n), n - количество деревьев
Сложность по памяти: O(n)
*/

std::vector<int> fillTreesVec(const int n)
{
    std::vector<int> trees;
    trees.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        trees.push_back(bufInt);
    }

    return trees;
}

std::pair<int, int> findMinSection(const int n, const int k, const std::vector<int> &trees)
{
    int right = 0;

    //словарь пород деревьев
    std::unordered_map<int, int> treesQuantity;

    //значение найденного на данный момент минимального отрезка
    int minLength = INT_MAX;

    // минимальный отрезок, содержащий все породы деревьев
    std::pair<int, int> minSection; 

    // двигаем левый указатель по 1
    for (int left = 0; left < n; ++left)
    {
        // двигаем вправо, пока хотя бы какого-то вида деревьев 0
        while (right < n && treesQuantity.size() < k)
        {
            ++treesQuantity[trees[right]];
            ++right;
        }
        // двигаем влево по шагу, пока одного вида дерева не станет 0
        if (treesQuantity.size() == k)
        {
            // вычисляем значение отрезка и обновляем ()при необходимости
            // right уже не следующей позиции, поэтому не делаем +1
            int bufLength = right - left;
            if (bufLength < minLength)
            {
                minLength = bufLength;
                minSection.first = left;
                // right уже не следующей позиции, поэтому делаем -1
                minSection.second = right - 1;
            }
            --treesQuantity[trees[left]];
            if (treesQuantity[trees[left]] == 0)
            {
                treesQuantity.erase(trees[left]);
            }
        }
    }

    return minSection;
}

int main()
{
    //считываем количество деревьев и количество сортов
    int n, k;
    std::cin >> n >> k;

    //считываем вектор, описывающий, как посажены деревья
    std::vector<int> trees = fillTreesVec(n);

    // находим минимальный отрезок, содержащий все деревья
    std::pair<int,int> result = findMinSection(n, k, trees);

    //выводим с учётом того, что в задаче счёт начинается с 1
    std::cout << result.first + 1 << " " << result.second + 1 << std::endl;

    return 0;
}