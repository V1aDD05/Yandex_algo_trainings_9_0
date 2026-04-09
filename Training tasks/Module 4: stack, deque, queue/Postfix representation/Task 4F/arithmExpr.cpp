#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

bool postfixStackProcessing(string &postfixStr, stack<char> &postfixStack, const char newChar)
{
    bool isPossible = true;
    if (newChar == '-' || newChar == '+')
    {
        while (!postfixStack.empty() && (postfixStack.top() == '+' || postfixStack.top() == '-' || postfixStack.top() == '*'))
        {
            postfixStr += postfixStack.top();
            postfixStr += ' ';

            postfixStack.pop();
        }
        postfixStack.push(newChar);
    }
    else if (newChar == '*')
    {
        while (!postfixStack.empty() && (postfixStack.top() == '*'))
        {
            postfixStr += postfixStack.top();
            postfixStr += ' ';

            postfixStack.pop();
        }
        postfixStack.push(newChar);
    }
    else if (newChar == '(')
    {
        postfixStack.push(newChar);
    }
    else if (newChar == ')')
    {
        isPossible = false;
        while (!postfixStack.empty() && postfixStack.top() != '(')
        {
            postfixStr += postfixStack.top();
            postfixStr += ' ';
            postfixStack.pop();
        }
        if (!postfixStack.empty() && postfixStack.top() == '(')
        {
            isPossible = true;
            postfixStack.pop();
        }
    }
    return isPossible;
}

void postfixComputation(string &postfixStr)
{
    stack<int> operands;

    char bufChar;
    string intStr;
    bool isInsideInt = false;

    istringstream iss(postfixStr);

    int left, right;
    bool isCorrect = true;

    while (iss.get(bufChar) && bufChar != '\n')
    {
        if (isInsideInt)
        {
            if (bufChar == ' ')
            {
                isInsideInt = false;
                operands.push(stoi(intStr));
                intStr.clear();
            }
            else
            {
                intStr.push_back(bufChar);
            }
        }
        else if (bufChar != ' ')
        {
            if (bufChar == '+' || bufChar == '-' || bufChar == '*')
            {
                if (!operands.empty())
                {
                    right = operands.top();
                    operands.pop();
                }
                else
                {
                    isCorrect = false;
                    break;
                }

                if (!operands.empty())
                {
                    left = operands.top();
                    operands.pop();
                }
                else
                {
                    isCorrect = false;
                    break;
                }

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
            else
            {
                intStr.push_back(bufChar);
                isInsideInt = true;
            }
        }
    }

    if (!isCorrect)
    {
        cout << "WRONG" << endl;
    }
    else
    {
        if (!intStr.empty())
        {
            operands.push(stoi(intStr));
        }
        if (intStr.size() <= 1)
        {
            cout << operands.top() << endl;
        }
        else
        {
            cout << "WRONG" << endl;
        }
    }
}

void wrap(const string &input)
{
    ifstream inputFile(input);
    string postfixStr = "";
    stack<char> postfixStack;

    bool isPossible = true;

    char bufChar;

    string intStr = "";
    bool isInsideInt = false;

    // o - operation, i - integer,b - opening bracket, c - closing bracket
    char previous = ' ';
    bool unarySuspect = true;

    while (inputFile.get(bufChar) && bufChar != '\n')
    {
        if (bufChar == ' ')
        {
            if (isInsideInt)
            {
                postfixStr += intStr;
                postfixStr += ' ';
                intStr.clear();
            }
            isInsideInt = false;
            unarySuspect = false;
        }
        else if (bufChar - '0' >= 0 && bufChar - '0' <= 9)
        {
            if (isInsideInt)
            {
                intStr.push_back(bufChar);
            }
            else
            {
                if (previous == 'o' || previous == 'b' || previous == ' ')
                {
                    isInsideInt = true;
                    unarySuspect = false;
                    previous = 'i';
                    intStr.push_back(bufChar);
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }
        }
        else if (bufChar == '-')
        {
            if (unarySuspect)
            {
                unarySuspect = false;
                previous = 'o';
                postfixStr += "0 ";
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
            }
            else
            {
                if (previous == 'i' || previous == 'c')
                {
                    if (isInsideInt)
                    {
                        postfixStr += intStr;
                        postfixStr += ' ';
                        intStr.clear();
                        isInsideInt = false;
                    }
                    previous = 'o';
                    isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }
        }
        else if (bufChar == '+' || bufChar == '*')
        {
            if (previous == 'i' || previous == 'c')
            {
                if (isInsideInt)
                {
                    postfixStr += intStr;
                    postfixStr += ' ';
                    intStr.clear();
                    isInsideInt = false;
                }
                previous = 'o';
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
            }
            else
            {
                isPossible = false;
                break;
            }
        }
        else if (bufChar == '(')
        {
            if (previous == 'o' || previous == ' ' || previous == 'b')
            {
                previous = 'b';
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
            }
            else
            {
                isPossible = false;
                break;
            }
            unarySuspect = true;
        }
        else if (bufChar == ')')
        {
            unarySuspect = false;
            if (previous == 'i' || previous == 'c')
            {
                if (isInsideInt)
                {
                    postfixStr += intStr;
                    postfixStr += ' ';
                    intStr.clear();
                    isInsideInt = false;
                }
                previous = 'c';
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
                if (!isPossible)
                {
                    break;
                }
            }
            else
            {
                isPossible = false;
                break;
            }
        }
        else
        {
            isPossible = false;
            break;
        }
    }

    if (!intStr.empty())
    {
        postfixStr += intStr;
        postfixStr += ' ';
    }

    // осталось вытолкнуть из стека оставшиеся там операции
    while (!postfixStack.empty())
    {
        if (postfixStack.top() == '+' || postfixStack.top() == '-' || postfixStack.top() == '*')
        {
            postfixStr += postfixStack.top();
            postfixStr += ' ';
            postfixStack.pop();
        }
        // случай, если там остались открывающие скобки
        else
        {
            isPossible = false;
            break;
        }
    }

    if (!postfixStr.empty() && isPossible)
    {
        postfixStr.pop_back();
        postfixComputation(postfixStr);
    }
    else
    {
        cout << "WRONG" << endl;
    }
}

int main()
{
#ifdef LOCAL
    string test;
    int n = 15;
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