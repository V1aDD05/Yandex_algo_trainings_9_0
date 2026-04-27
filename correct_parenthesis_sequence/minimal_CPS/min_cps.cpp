#include <iostream>
#include <string>
#include <stack>

std::stack<char> fillStack(const std::string &s)
{
    std::stack<char> charStack;
    for (const auto &bufChar : s)
    {
        if (bufChar == '(')
        {
            charStack.push('(');
        }
        else if (bufChar == '[')
        {
            charStack.push('[');
        }
        else if (bufChar == ')')
        {
            if (charStack.top() == '(')
            {
                charStack.pop();
            }
        }
        else if (bufChar == ']')
        {
            if (charStack.top() == '[')
            {
                charStack.pop();
            }
        }
    }

    return charStack;
}

std::string complementCPS(std::string &s, const std::string& alphabet, const int n)
{
    std::stack<char> charStack = fillStack(s);

    size_t pointer = s.size();

    size_t alpSize = alphabet.size();

    // дозаполняем строку исходного размера 'pointer' до размера 'n'
    while (pointer < n)
    {
        for (const auto &alphChar : alphabet)
        {
            if (alphChar == '(' && (n - pointer > charStack.size()))
            {
                charStack.push(alphChar);
                s.push_back(alphChar);
                break;
            }
            else if (alphChar == '[' && (n - pointer > charStack.size()))
            {
                charStack.push(alphChar);
                s.push_back(alphChar);
                break;
            }
            else if (alphChar == ')' && !charStack.empty() && charStack.top() == '(')
            {
                charStack.pop();
                s.push_back(alphChar);
                break;
            }
            else if (alphChar == ']' && !charStack.empty() && charStack.top() == '[')
            {
                charStack.pop();
                s.push_back(alphChar);
                break;
            }
        }
        ++pointer;
    }
    return s;
}


int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string alphabet;
    std::cin >> alphabet;

    std::string s;
    std::cin >> s;

    std::cout << complementCPS(s, alphabet, n) << std::endl;

    return 0;
}