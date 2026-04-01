#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n;
    inputFile >> n;

    vector<int> cookiesType;
    cookiesType.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        cookiesType.push_back(bufInt);
    }

    unordered_map<int, int> cookiesMap;

    int maxLen = 0;

    int left = 0;
    int right = 0;

    while (right < n)
    {
        ++cookiesMap[cookiesType[right]];
        size_t mapSize = cookiesMap.size();
        if (mapSize == 2)
        {
            int bufLen = right - left + 1;
            maxLen = max(maxLen, bufLen);
        }
        else if (mapSize > 2)
        {
            while (cookiesMap.size() > 2)
            {
                --cookiesMap[cookiesType[left]];
                if (cookiesMap[cookiesType[left]] == 0)
                {
                    cookiesMap.erase(cookiesType[left]);
                }
                ++left;
            }
        }
        ++right;
    }

    cout << maxLen << endl;

    //
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

#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}