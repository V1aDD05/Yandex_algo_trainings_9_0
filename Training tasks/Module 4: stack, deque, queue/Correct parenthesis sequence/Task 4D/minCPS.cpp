#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n;
    inputFile >> n;
    inputFile.ignore();

    vector<char> alphabet;
    alphabet.reserve(4);

    char bufChar;
    while (inputFile.get(bufChar) && bufChar != '\n')
    {
        alphabet.push_back(bufChar);
    }

    size_t alpSize = alphabet.size();

    string s;
    s.reserve(n);
    getline(inputFile, s);
    size_t sSize = s.size();

    stack<char> charStack;
    for (size_t i = 0; i < sSize; ++i)
    {
        if (s[i] == '(')
        {
            charStack.push('(');
        }
        else if (s[i] == '[')
        {
            charStack.push('[');
        }
        else if (s[i] == ')')
        {
            if (charStack.top() == '(')
            {
                charStack.pop();
            }
        }
        else if (s[i] == ']')
        {
            if (charStack.top() == '[')
            {
                charStack.pop();
            }
        }
    }

    size_t pointer = sSize;
    while (pointer < n)
    {
        for (size_t i = 0; i < alpSize; ++i)
        {
            char alphChar = alphabet[i];
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
    cout << s << endl;

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

    // 2
    test = "test2.txt";
    cout << "****************" << endl;
    cout << "       TEST 2" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 3
    test = "test3.txt";
    cout << "****************" << endl;
    cout << "       TEST 3" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 4
    test = "test4.txt";
    cout << "****************" << endl;
    cout << "       TEST 4" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 5
    test = "test5.txt";
    cout << "****************" << endl;
    cout << "       TEST 5" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 6
    test = "test6.txt";
    cout << "****************" << endl;
    cout << "       TEST 6" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 7
    test = "test7.txt";
    cout << "****************" << endl;
    cout << "       TEST 7" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 8
    test = "test8.txt";
    cout << "****************" << endl;
    cout << "       TEST 8" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 9
    test = "test9.txt";
    cout << "****************" << endl;
    cout << "       TEST 9" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 10
    test = "test10.txt";
    cout << "****************" << endl;
    cout << "       TEST 10" << endl;
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