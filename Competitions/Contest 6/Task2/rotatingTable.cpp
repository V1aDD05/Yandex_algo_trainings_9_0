#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string& input){
    ifstream inputFile(input);

    int n;
    inputFile >> n;

    vector<bool> goodShifts(n, true);
    vector<int> initialPlacement(n);
    int bufInt;
    for (int i = 0; i < n; ++i)
    {
        inputFile >> bufInt;
        initialPlacement[i] = bufInt - 1;
    }

    for (int i = 0; i < n; ++i) {
        int shift = initialPlacement[i] - i;
        if (shift < 0) {
            shift += n;
        }
        goodShifts[shift] = false;
    }

    int minShift = -1;
    for (int i = 0; i < n; ++i)
    {
        if (goodShifts[i] == true) {
            minShift = i;
            break;
        }
    }
    cout << minShift << endl;
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
#else
    string input = "input.txt";
    wrap(input);
    
#endif

    return 0;
}