#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n, k;

    inputFile >> n >> k;

    string stroke;
    inputFile >> stroke;

    unordered_map<char, int> alphabet;

    int maxLen = 0;
    int result;

    int left = 0;
    int right = 0;

    while (right < n)
    {
        ++alphabet[stroke[right]];
        if (alphabet[stroke[right]] > k)
        {
            int bufLen = right - left;
            if (bufLen > maxLen)
            {
                maxLen = bufLen;
                result = left;
            }
            while (alphabet[stroke[right]] > k)
            {
                --alphabet[stroke[left]];
                ++left;
            }
        }
        ++right;
    }

    int bufLen = right - left;
    if (bufLen > maxLen)
    {
        maxLen = bufLen;
        result = left;
    }

    if (!maxLen)
    {
        maxLen = n;
        result = 0;
    }

    cout << maxLen << " " << result + 1 << endl;
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}