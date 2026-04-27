#include <iostream>
#include <unordered_set>

/*
Сложность по времени: O(N)
Сложность по памяти: O(N).
*/

int main()
{  
    std::unordered_set<int> intSet;
    size_t uniqueCounter = 0;

    int buf;
    while (std::cin >> buf)
    {
        auto it = intSet.find(buf);
        // если число в наборе встречается впервые,
        // добавляем его в множество и инкременитруем счётчик
        if (it == intSet.end())
        {
            ++uniqueCounter;
            intSet.insert(buf);
        }
    }

   std::cout << uniqueCounter << std::endl;

    return 0;
}