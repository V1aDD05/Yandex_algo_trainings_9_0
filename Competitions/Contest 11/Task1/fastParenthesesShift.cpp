#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

bool checkCPS(const string &candidate, size_t strSize)
{
    bool checkResult = true;

    stack<char> cpsStack;

    for (size_t i = 0; i < strSize; ++i)
    {
        char bufChar = candidate[i];
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

void wrap(const string &input)
{
    ifstream inputFile(input);
    string start;
    inputFile >> start;

    bool isCSP = false;

    size_t strSize = start.size();

    if (!strSize)
    {
        isCSP = true;
    }
    if (strSize % 2 != 0)
    {
        isCSP = false;
    }
    else
    {
        for (size_t i = 0; i < strSize; ++i)
        {
            string candidate = start.substr(i, strSize - i) + start.substr(0, i);
            isCSP = checkCPS(candidate, strSize);
            if (isCSP)
            {
                break;
            }
        }
    }

    if (!isCSP)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int main()
{
#ifdef LOCAL
    string test;
    int n = 5;
    for (int i = 1; i <= n; ++i)
    {
        test = "test" + to_string(i) + ".txt";
        cout << "****************" << endl;
        cout << "       TEST " << i << endl;
        cout << "****************" << endl;
        wrap(test);
        cout << endl;
        cout << endl;
    }
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}