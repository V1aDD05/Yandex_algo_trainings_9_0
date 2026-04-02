#include <bits/stdc++.h>

using namespace std;

#define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n;
    inputFile >> n;

    vector<int> integers;
    integers.reserve(n);

    vector<long long int> prefSums;
    prefSums.reserve(n + 1);
    prefSums.push_back(0);

    int mod = 1000000007;

    //формирование вектора чисел и
    //вычисление вектора префиксных сумм 
    for (int i = 0; i < n; ++i) {
        int bufInt;
        inputFile >> bufInt;
        integers.push_back(bufInt);

        prefSums.push_back((prefSums[i] + bufInt) % mod);
    }

    vector<long long int> suffSums(n+1);

    suffSums[n] = 0;

    // вычисление вектора суффиксных сумм
    int rightBound = n - 1;
    for (int i = rightBound; i >= 0; --i)
    {
        int bufInt = integers[i];
        //использовать insert() нельзя - O(n^2)
        suffSums[i] = (suffSums[i + 1] + bufInt) % mod;
    }

    // непосредтвенно подсчёт сумм как prefSums[j] * aj * suffSums[j + 1]
    int sum = 0;
    for (int j = 1; j < rightBound; ++j)
    {

        long long int mul = (((static_cast<long long int>(prefSums[j]) * integers[j]) % mod) * suffSums[j + 1]) % mod;
        sum = (sum + mul) % mod;
    }

    cout << sum << endl;
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}