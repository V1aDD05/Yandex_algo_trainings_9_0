#include <iostream>
#include <vector>

/*
Сложность по времени: O(n).
Сложность по памяти: O(n).
*/

int main()
{
    int cases;
    std::cin >> cases;

    for (int i = 0; i < cases; ++i)
    {
        int n, d;
        std::cin >> n >> d;

        //вектор "терпения" для каждого человека в очереди
        std::vector<int> patience;
        patience.reserve(n);

        //вектор суммарного времени ожидания для каждого человека в очереди
        std::vector<long long int> prefSum;
        prefSum.reserve(n + 1);
        prefSum.push_back(0);

        for (int j = 0; j < n; ++j)
        {
            int ti, ki;
            std::cin >> ti >> ki;
            patience.push_back(ti);
            prefSum.push_back(prefSum[j] + ki);
        }

        int left = 0;

        for (int j = 0; j < n; ++j)
        {   
            //если предел терпения человека меньше суммарного времени ожидания
            //плюс времени заказа Васи, Вася сдвигается правее этого человека
            if (prefSum[j] + d > patience[j])
            {
                left = j + 1;
            }
        }

        //добавляем единицу, т.к. в условии задачи счёт с 1
        std::cout << left + 1 << std::endl;
    }

    return 0;
}