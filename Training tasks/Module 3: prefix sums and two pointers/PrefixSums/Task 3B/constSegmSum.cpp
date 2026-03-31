#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n;
    inputFile >> n;

    //запросов будет много, поэтому будем хранить префиксные суммы
    vector<long long int> sums(n + 1);
    sums[0] = 0;

    //формируем вектор префиксных сумм по входным данным
    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        sums[i + 1] = sums[i] + bufInt;
    }

    int q, x0;
    inputFile >> q >> x0;

    //сумма всех запросов
    long long int requestSum = 0;

    //числа из последовательности для данной итерации
    pair<int, int> xs;
    xs.first = x0;
    xs.second = (static_cast<long long int>(x0) * 11173 +1) % 1000000007;

    for (int i = 0; i < q; ++i)
    {
        int L = min(xs.first % n, xs.second % n);
        int R = max(xs.first % n, xs.second % n);

        requestSum += sums[R+1] - sums[L];

        // числа из последовательности для следующей итерации
        xs.first = (static_cast<long long int>(xs.second) * 11173 + 1) % 1000000007;
        xs.second = (static_cast<long long int>(xs.first) * 11173 + 1) % 1000000007;
    }

    cout << requestSum % 1000000007 << endl;
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}