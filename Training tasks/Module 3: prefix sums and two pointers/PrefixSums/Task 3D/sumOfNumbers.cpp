#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

void wrap(const string& input){
    ifstream inputFile(input);
    unordered_set<int> prefs;
    prefs.insert(0);

    auto it = prefs.begin();

    int n, k;
    inputFile >> n >> k;

    int prefSum = 0;
    int counter = 0;

    for (int i = 0; i < n; ++i) {
        int bufInt;
        inputFile >> bufInt;
        prefSum += bufInt;
        prefs.insert(prefSum);
        // можно было и выделить в отдельную ветку: немного быстрее при
        // значительном кол-ве bufInt == k, но менее читаемо
        /*
        if (bufInt == k) {
            ++counter;
        }
        */

        // в принципе, можно было искать для всех bufInt
        if (bufInt <= k)
        {
            it = prefs.find(prefSum - k);
            if (it != prefs.end()) {
                ++counter;
            }
        }
    }
    cout << counter <<endl;
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
#else
    string input = "input.txt";
    wrap(input);
#endif

    return 0;
}