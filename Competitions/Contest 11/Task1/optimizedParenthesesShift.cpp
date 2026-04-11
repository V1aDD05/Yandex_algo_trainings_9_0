#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

bool checkCPS(const string& candidate, size_t shift) {
    bool checkResult = true;

    size_t strSize = candidate.size();

    stack<char> cpsStack;

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

void wrap(const string &input)
{
    ifstream inputFile(input);
    string start;
    inputFile >> start;

    bool isCPS = false;

    size_t strSize = start.size();

    if (!strSize)
    {
        isCPS = true;
    }
    else {
        for (size_t i = 0; i < strSize; ++i)
        {
            isCPS = checkCPS(start, i);
            if (isCPS)
            {
                break;
            }
        }
    }

    if (!isCPS)
    {
        cout << "NO" << endl;
    }
    else {
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