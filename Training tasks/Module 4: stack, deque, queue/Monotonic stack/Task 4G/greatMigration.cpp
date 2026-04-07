#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n;
    inputFile >> n;

    stack<pair<int, int>> townStack;
    vector<pair<int, int>> towns;
    towns.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int bufCost;
        inputFile >> bufCost;
        towns.push_back({bufCost, -1});
        while (!townStack.empty() && townStack.top().first > bufCost)
        {
            int bufIndex = townStack.top().second;
            towns[bufIndex].second = i;
            townStack.pop();
        }
        townStack.push({bufCost, i});
    }

    bool isFirst = true;
    for (const auto &town : towns)
    {
        if (isFirst)
        {
            isFirst = false;
            cout << town.second;
        }
        else {
            cout << ' ' << town.second;
        }
    }
    cout << endl;
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}