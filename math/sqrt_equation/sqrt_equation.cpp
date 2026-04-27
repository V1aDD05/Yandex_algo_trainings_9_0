#include <iostream>
#include <fstream>
#include <utility>  //std::pair

/*
Сложность по времени: O(1).
Сложность по памяти: O(1)
*/

std::pair<int, int> solveEquation(int a, int b, int c)
{

    //первое число - решение (при наличии), второе - код
    //'0' - нет решений, '1' - одно решение, '2' - много решений
    std::pair<int, int> output;

    if (c < 0)
    {
        output = {0, 0};
    }
    else
    {
        if (!a)
        {
            if (b == c * c)
            {
                output = {0, 2};
            }
            else
            {
                output = {0, 0};
            }
        }
        else
        {
            if ((c * c - b) % a == 0)
            {
                int x = (c * c - b) / a;
                if (a > 0)
                {
                    if (x >= (static_cast<double>(-b) / a))
                    {
                        output = {x, 1};
                    }
                    else
                    {
                        output = {0, 0};
                    }
                }
                else
                {
                    if (x <= (static_cast<double>(-b) / a))
                    {
                        output = {x, 1};
                    }
                    else
                    {
                        output = {0, 0};
                    }
                }
            }
            else
            {
                output = {0, 0};
            }
        }
    }

    return output;
}

int main()
{
    int a, b, c;

    std::cin >> a >> b >> c;

    std::pair<int, int> result = solveEquation(a, b, c);

    if (result.second == 1)
    {
        std::cout << result.first << std::endl;
    }
    else if (result.second == 0)
    {
        std::cout << "NO SOLUTION" << std::endl;
    }
    else if (result.second == 2)
    {
        std::cout << "MANY SOLUTIONS" << std::endl;
    }

    return 0;
}