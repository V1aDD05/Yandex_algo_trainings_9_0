#include <iostream>
#include <string>
#include <stack>

/*
Сложность по времени: O(n^2), n - размер входной СП
Сложность по памяти: O(n)
*/


//функция проверки на правильную скобочную последовательность (ПСП)
bool checkCPS(const std::string& candidate, size_t shift) 
{
    //флаг правильности скобочной последовательности
    bool checkResult = true;

    size_t strSize = candidate.size();

    //стек, применяемый для проверки на ПСП
    std::stack<char> cpsStack;

    for (size_t i = 0; i < strSize; ++i)
    {
        //обходим полученную на вход СП с учётом заданного смещения
        size_t position = (i + shift) % strSize;
        char bufChar = candidate[position];
        if (bufChar == '(' || bufChar == '[' || bufChar == '{')
        {
            cpsStack.push(bufChar);
        }
        else if (bufChar == ')')
        {
            if (!cpsStack.empty() && cpsStack.top() == '(')
            {
                cpsStack.pop();
            }
            else
            {
                checkResult = false;
                break;
            }
        }
        else if (bufChar == '}')
        {
            if (!cpsStack.empty() && cpsStack.top() == '{')
            {
                cpsStack.pop();
            }
            else
            {
                checkResult = false;
                break;
            }
        }
        else if (bufChar == ']')
        {
            if (!cpsStack.empty() && cpsStack.top() == '[')
            {
                cpsStack.pop();
            }
            else
            {
                checkResult = false;
                break;
            }
        }
    }

    //СП правильная, если после обработки всей последовательности стек пустой
    if (!cpsStack.empty())
    {
        checkResult = false;
    }

    return checkResult;
}


int main()
{
    //считываем скобочную последовательность
    std::string start;
    std::cin >> start;

    //флаг правильной скобочной последовательности (ПСП)
    bool isCPS = false;
    size_t strSize = start.size();

    //пустая скобочная последовательность по определению правильная
    if (!strSize)
    {
        isCPS = true;
    }
    else
    {
        //поэлементно "сдвигаем" элементы исходной скобочной последовательности
        //и проверяем получившуюся последовательность на ПСП
        for (size_t i = 0; i < strSize; ++i)
        {
            isCPS = checkCPS(start, i);
            //достаточно найти один сдвиг, при котором СП правильная
            if (isCPS)
            {
                break;
            }
        }
    }

    if (!isCPS)
    {
        std::cout << "NO" << std::endl;
    }
    else
    {
        std::cout << "YES" << std::endl;
    }

    return 0;
}