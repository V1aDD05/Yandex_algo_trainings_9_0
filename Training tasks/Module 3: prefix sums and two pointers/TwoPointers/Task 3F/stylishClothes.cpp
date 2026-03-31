#include <bits/stdc++.h>

using namespace std;

#define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n, m, k;
    inputFile >> n;

    vector<int> tShirts(n);

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        tShirts[i] = bufInt;
    }

    inputFile >> m;

    vector<int> trousers(m);

    for (int i = 0; i < m; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        trousers[i] = bufInt;
    }

    k = n + m;

    int minAbs = INT_MAX;
    pair<int, int> closestPair;

    int tShirtsPtr = 0;
    int trousersPtr = 0;

    for (int i = 0; i < k-1; ++i) {
        int tShirtsTemp = tShirts[tShirtsPtr];
        int trousersTemp = trousers[trousersPtr];

        int absTemp = abs(tShirtsTemp - trousersTemp);

        // проверяем, насколько текущие значения подходят друг к другу
        if (absTemp < minAbs)
        {
            minAbs = absTemp;
            closestPair.first = tShirtsTemp;
            closestPair.second = trousersTemp;
        }

        //меньше нуля различие быть не может, по условию
        //выводим любую пару с минимальным различием -> дальше можно не перебирать
        if (!minAbs) {
            break;
        }

        // выбираем сдвиг для следующей итерации
        if (tShirtsPtr == n - 1 || (tShirtsTemp > trousersTemp && trousersPtr < m - 1))
        {
            ++trousersPtr;
        }
        else
        {
            ++tShirtsPtr;
        }
    }

    cout << closestPair.first << " " << closestPair.second << endl;
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

#else
    string input = "input.txt";
    wrap(input);
#endif

    return 0;
}