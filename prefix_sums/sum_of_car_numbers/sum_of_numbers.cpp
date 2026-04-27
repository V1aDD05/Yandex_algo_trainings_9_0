#include <iostream>
#include <unordered_set>

/*
Сложность по времени: O(N)
Сложность по памяти: O(N).
*/

int main()
{
    //считываем количество машин и "любимое" число 
    int n, k;
    std::cin >> n >> k;

    // последовательность строго возрастающая, достаточно set
    std::unordered_set<int> prefs;
    prefs.insert(0);

    //префиксная сумма
    int prefSum = 0;

    //счётчик наборов
    int counter = 0;

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        prefSum += bufInt;
        prefs.insert(prefSum);

        // если введённое число > k, то условие выполнено не будет
        // (все числа положительные)
        if (bufInt <= k)
        {
            //если есть в наборе элемент, на k меньший
            //текущего значения префиксной суммы, значит,
            //обнаружен новый набор машин, удовлетворяющий условию
            auto it = prefs.find(prefSum - k);
            if (it != prefs.end())
            {
                ++counter;
            }
        }
    }

    std::cout << counter << std::endl;

    return 0;
}