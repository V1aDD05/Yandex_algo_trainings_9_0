#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n;
    inputFile >> n;

    string order;
    inputFile >> order;

    int left;
    int right;

    unordered_map<int, int> quantity;
    quantity[0] = 1;
    int prefDiff = 0;

    for (int i = 0; i < n; ++i)
    {
        char bufChar = order[i];
        if (bufChar == 'a') {
            ++prefDiff;
        }
        else if (bufChar == 'b')
        {
            --prefDiff;
        }
        ++quantity[prefDiff];
    }

    auto it = quantity.begin();
    auto itEnd = quantity.end();
    long long int result = 0;

    while (it != itEnd)
    {
        result += static_cast<long long int>(it->second) * (it->second - 1) / 2;
        ++it;
    }

    cout << result << endl;
    
}

int main()
{
#ifdef LOCAL
    string test;
    /*
    // 1
    test = "test1.txt";
    cout << "****************" << endl;
    cout << "       TEST 1" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;
    
    */
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}