#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int cases;
    inputFile >> cases;

    for (int i = 0; i < cases; ++i) {
        int n, d;
        inputFile >> n >> d;

        vector<int> patience;
        patience.reserve(n);

        vector<int> prefSum(n+1);
        prefSum[0] = 0;

        
        for (int j = 0; j < n; ++j)
        {
            int ti, ki;
            inputFile >> ti >> ki;
            patience.push_back(ti);
            prefSum[j + 1] = prefSum[j] + ki;
        }

        int left = 0;

        for (int j = 0; j < n; ++j) {
            if (prefSum[j] + d > patience[j]) {
                left = j + 1;
            }
        }

        cout << left + 1 << endl;
    }
}

// void test(){}

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
    */
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}