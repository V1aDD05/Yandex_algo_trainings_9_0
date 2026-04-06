#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    vector<int> operands;
    vector<pair<char, int>> operators;
    int operandsCounter = 0;

    char bufChar;
    string intStr;
    bool isInsideInt = false;

    while (inputFile.get(bufChar) && bufChar != '\n')
    {
        if (isInsideInt)
        {
            if (bufChar == ' ')
            {
                isInsideInt = false;
                operands.push_back(stoi(intStr));
                intStr.clear();
                ++operandsCounter;
            }
            else {
                intStr.push_back(bufChar);
            }
        }
        else if (bufChar != ' ')
        {
            if (bufChar == '+' || bufChar == '-' || bufChar == '*' || bufChar == '/')
            {
                operators.push_back({bufChar, operandsCounter});
            }
            else {
                intStr.push_back(bufChar);
                isInsideInt = true;
            }
        }
    }

    int deductibleCoef = 1;



    for (const auto &op : operators)
    {
        int left = operands[op.second - deductibleCoef - 1];
        int right = operands[op.second - deductibleCoef];
        if (op.first == '+')
        {
            operands[op.second - deductibleCoef] = left + right;
        }
        else if (op.first == '-')
        {
            operands[op.second - deductibleCoef] = left - right;
        }
        else if (op.first == '*')
        {
            operands[op.second - deductibleCoef] = left * right;
        }
        else if (op.first == '/')
        {
            operands[op.second - deductibleCoef] = left / right;
        }

        auto it = operands.begin() + op.second - deductibleCoef - 1;
        operands.erase(it);
        ++deductibleCoef;
    }

    cout << operands[0] << endl;
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