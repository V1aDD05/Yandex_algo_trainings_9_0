#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int bufInt;
    int queueStartSize = 5;

    queue<int> first;
    for (int i = 0; i < queueStartSize; ++i)
    {
        inputFile >> bufInt;
        first.push(bufInt);
    }

    queue<int> second;
    for (int i = 0; i < queueStartSize; ++i)
    {
        inputFile >> bufInt;
        second.push(bufInt);
    }

    int counter = 0;
    int counterMax = 1000000;
    while (!first.empty() && !second.empty() && counter < counterMax)
    {
        int topFirst = first.front();
        first.pop();

        int topSecond = second.front();
        second.pop();

        if ((topSecond == 0 && topFirst == 9) || (topFirst < topSecond && (topFirst || topSecond != 9)))
        {
            second.push(topFirst);
            second.push(topSecond);
        }
        else {
            first.push(topFirst);
            first.push(topSecond);
        }
        ++counter;
    }

    if (first.empty())
    {
        cout << "second " << counter << endl;
    }
    else if (second.empty())
    {
        cout << "first " << counter << endl;
    }
    else if (counter == counterMax)
    {
        cout << "botva" << endl;
    }
}

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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}