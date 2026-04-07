#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    stack<int> operands;

    char bufChar;
    int left, right;

    while (inputFile.get(bufChar) && bufChar != '\n')
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

    cout << operands.top() << endl;
    operands.pop();
}

// void test(){}

int main()
{
#ifdef LOCAL
    string test;
    // 1
    test = "test1.txt";
    cout << "****************" << endl;
    cout << "       TEST 1" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}