#include <iostream>
#include <stack>

/*
Сложность по времени: O(n), n - размер входной СП
Сложность по памяти: O(n)
*/

int main()
{

    /*
    Не стали выносить логику в отдельную функцию, чтобы не выделять
    дополнительную структуру для хранения входных данных,
    подробнее см. Readme, раздел "Примечание по реализации"
    */

    // стек, применяемый для проверки на 
    // правильную скобочную последовательность (ПСП)
    std::stack<char> cpsStack;

    // флаг правильности скобочной последовательности
    bool isCPS = true;

    char bufChar;
    while (std::cin.get(bufChar) && bufChar != '\n')
    {
        if (bufChar == '(' || bufChar == '{' || bufChar == '[')
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
                isCPS = false;
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
                isCPS = false;
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
                isCPS = false;
                break;
            }
        }
    }

    // СП правильная, если после обработки всей последовательности стек пустой
    if (!cpsStack.empty())
    {
        isCPS = false;
    }

    if (isCPS)
    {
        std::cout << "yes" << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
    }

    return 0;
}