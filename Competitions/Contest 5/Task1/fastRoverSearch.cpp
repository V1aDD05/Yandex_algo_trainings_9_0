#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string& input){
    ifstream inputFile(input);

    int n, xi, di;

    inputFile >> n;

    vector<pair<int, int>> signals;

    for (int i = 0; i < n; ++i) {
        inputFile >> xi >> di;
        signals.push_back(make_pair(xi - di, xi + di));
    }

    pair<int, int> intersection = signals[0];

    pair<int, int> bufPair;

    for (int i = 1; i < n; ++i) {
        bufPair = signals[i];
        int moreLeft = max(intersection.first, bufPair.first);
        int lessRight = min(intersection.second, bufPair.second);

        if (moreLeft > lessRight) {
            intersection.second = -1;
            break;
        }
        else if (moreLeft == lessRight) {
            intersection.first = moreLeft;
            intersection.second = moreLeft;
        }
        else if (moreLeft < lessRight) {
            intersection.first = moreLeft;
            intersection.second = lessRight;
        }
    }

    cout << intersection.second << endl;
}

// void test(){}

int main()
{
#ifdef LOCAL
    // объявить те же переменные, что и в основной части

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