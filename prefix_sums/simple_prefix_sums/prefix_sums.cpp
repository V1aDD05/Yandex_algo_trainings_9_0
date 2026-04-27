#include <iostream>

/*
Сложность по времени: O(N)
Сложность по памяти: O(1).
*/

// #define LOCAL

int main()
{
    //считываем количество элементов в последовательности
    int n;
    std::cin >> n;

    //Для указанных данных переполнения не будет
    int prefSum = 0;

    //считаем и сразу выводим префиксные суммы
    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        prefSum += bufInt;
        if (i)
        {
            std::cout << " ";
        }
        std::cout << prefSum;
    }
    std::cout << std::endl;

    return 0;
}