#include <iostream>
#include <stack>

int main()
{

    /*
    Не стали выносить логику в отдельную функцию, чтобы не выделять
    дополнительную структуру для хранения входных данных,
    подробнее см. Readme, раздел "Примечание по реализации"
    */
    
    std::stack<char> cpsStack;
    char bufChar;

    bool isCPS = true;

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