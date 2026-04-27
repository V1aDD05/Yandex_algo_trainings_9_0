#include <iostream>
#include <queue>

/*
Сложность по времени: O(1) (по условию есть ограничение сверху)
Сложность по памяти: O(2*N) = O(N), N = queueStartSize.
*/

//функция, имитирующая ход игры и выводящая результат
void gameImitation(std::queue<int> &first, std::queue<int> &second) 
{
    int counter = 0;
    int counterMax = 1000000;
    while (!first.empty() && !second.empty() && counter < counterMax)
    {
        int topFirst = first.front();
        first.pop();

        int topSecond = second.front();
        second.pop();

        if ((topSecond == 0 && topFirst == 9) || (topFirst < topSecond && (topFirst != 0 || topSecond != 9)))
        {
            second.push(topFirst);
            second.push(topSecond);
        }
        else
        {
            first.push(topFirst);
            first.push(topSecond);
        }
        ++counter;
    }

    if (first.empty())
    {
        std::cout << "second " << counter << std::endl;
    }
    else if (second.empty())
    {
        std::cout << "first " << counter << std::endl;
    }
    else if (counter == counterMax)
    {
        std::cout << "botva" << std::endl;
    }
}

int main()
{
    //начальное число карт "на руках" у каждого из игроков
    int queueStartSize = 5;

    //считываем карты, розданные первому игроку
    std::queue<int> first;
    for (int i = 0; i < queueStartSize; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        first.push(bufInt);
    }

    // считываем карты, розданные второму игроку
    std::queue<int> second;
    for (int i = 0; i < queueStartSize; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        second.push(bufInt);
    }

    //имитируем ход игры, выводим результат
    gameImitation(first, second);

    return 0;
}