#include <iostream>
#include <unordered_set>

/*
Сложность по времени: O(N)
Сложность по памяти: O(N).
*/

int main()
{  
    std::unordered_set<int> intSet;

    int buf;
    while (std::cin >> buf)
    {
        auto it = intSet.find(buf);
        if (it == intSet.end())
        {
            std::cout << "NO" << std::endl;
            intSet.insert(buf);
        }
        else
        {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}