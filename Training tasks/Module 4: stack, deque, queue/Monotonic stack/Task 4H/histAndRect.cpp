#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int vecSize;
    inputFile >> vecSize;

    vector<tuple<int, int, int>> histVec;
    histVec.reserve(vecSize);

    int bufInt;
    while (inputFile >> bufInt)
    {
        histVec.push_back({bufInt, -1, -1});
    }


    for (int i = 0; i < vecSize; ++i)
    {
        get<1>(histVec[i]) = vecSize;
    }

    stack<pair<int, int>> histStack;
    for (int i = 0; i < vecSize; ++i)
    {
        int histHeight = get<0>(histVec[i]);
        while (!histStack.empty() && histStack.top().first > histHeight)
        {
            int index = histStack.top().second;
            histStack.pop();
            get<1>(histVec[index]) = i;
        }
        histStack.push({histHeight, i});
    }

    while (!histStack.empty())
    {
        histStack.pop();
    }

    for (int i = vecSize - 1; i >= 0; --i)
    {
        int histHeight = get<0>(histVec[i]);
        while (!histStack.empty() && histStack.top().first > histHeight)
        {
            int index = histStack.top().second;
            histStack.pop();
            get<2>(histVec[index]) = i;
        }
        histStack.push({histHeight, i});
    }

    while (!histStack.empty())
    {
        histStack.pop();
    }

    long long int maxSquare = 0;
    for (int i = 0; i < vecSize; ++i)
    {
        long long int bufSquare = static_cast<long long int>(get<0>(histVec[i])) * (get<1>(histVec[i]) - get<2>(histVec[i]) - 1);
        maxSquare = max(maxSquare, bufSquare);
    }

    cout << maxSquare << endl;
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}