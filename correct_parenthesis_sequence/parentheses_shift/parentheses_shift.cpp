#include <iostream>
#include <string>
#include <stack>

bool checkCPS(const std::string& candidate, size_t shift) {
    bool checkResult = true;

    size_t strSize = candidate.size();

    std::stack<char> cpsStack;

    for (size_t i = 0; i < strSize; ++i)
    {
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

    if (!cpsStack.empty())
    {
        checkResult = false;
    }

    return checkResult;
}


int main()
{

    std::string start;
    std::cin >> start;

    bool isCPS = false;
    size_t strSize = start.size();

    //пустая скобочная последовательность по определению правильная
    if (!strSize)
    {
        isCPS = true;
    }
    else
    {
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