#include <iostream>
#include <utility>  //std::pair
#include <stack>

/*
Сложность по времени: O(N)
Сложность по памяти: O(N)
*/

int main()
{
    //считываем количество шариков
    int n;
    std::cin >> n;
    
    int delCounter = 0; // счётчик удаляемых
    int rowCounter = 0; // счётчик одноцветных шариков, стоящих в ряд

    const int rowMin = 3;

    //стек неудалённых шариков
    //первое число в паре - код цвета, второе - количество таких, идущих в ряд
    std::stack<std::pair<int, int>> ballsOrder;

    for (int i = 0; i < n; ++i)
    {
        //считываем информацию о новом шарике
        int buf;
        std::cin >> buf;

        // если новый шар такого же цвета, что и предыдущий, инкрементируем rowCounter
        if (!ballsOrder.empty() && buf == ballsOrder.top().first)
        {
            ++rowCounter;
            ballsOrder.push({buf, rowCounter});
        }
        else
        {
            // если до этого в ряд стоит rowCounter >= rowMin одноцветных, проводим
            //  стирание ряда одинаковых, инкрементацию счётчика удалённых
            if (rowCounter >= rowMin)
            {
                for (int j = 0; j < rowCounter; ++j)
                {
                    ++delCounter;
                    ballsOrder.pop();
                }
            }

            // если buf имеет тот же тип, что и верхний из оставшихся шариков,
            // продолжаем серию шариков верхнего типа. 
            if (!ballsOrder.empty() && ballsOrder.top().first == buf)
            {
                rowCounter = ballsOrder.top().second + 1;
            }
            // Иначе начинаем заново. Здесь же обрабатываем случай 
            // ballsOrder.empty()
            else if (ballsOrder.empty() || !ballsOrder.empty() && ballsOrder.top().first != buf)
            {
                rowCounter = 1;
            }
            ballsOrder.push({buf, rowCounter});
        }
    }

    // обработка случая, когда 3 и более одинаковых шариков шли до конца набора
    if (rowCounter >= rowMin)
    {
        for (int j = 0; j < rowCounter; ++j)
        {
            ++delCounter;
            ballsOrder.pop();
        }
    }

    std::cout << delCounter << std::endl;

    return 0;
}