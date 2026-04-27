#include <iostream>
#include <stack>

/*
Сложность по времени: O(n).
Сложность по памяти: O(m), m - количество цифр, m < n
*/

int main()
{
    std::stack<int> operands;

    char bufChar;
    int left, right;

    while (std::cin.get(bufChar) && bufChar != '\n')
    {

        if (bufChar - '0' >= 0 && bufChar - '0' <= 9)
        {
            operands.push(bufChar - '0');
        }
        else if (bufChar == '+' || bufChar == '-' || bufChar == '*')
        {
            right = operands.top();
            operands.pop();
            left = operands.top();
            operands.pop();

            if (bufChar == '+')
            {
                operands.push(left + right);
            }
            else if (bufChar == '-')
            {
                operands.push(left - right);
            }
            else if (bufChar == '*')
            {
                operands.push(left * right);
            }
        }
    }

    std::cout << operands.top() << std::endl;
    operands.pop();

    return 0;
}