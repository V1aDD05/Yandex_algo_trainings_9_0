#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

int wrap(const long long int n, const long long int m, const long long int h, const long long int w)
{
    long long int counter = 0;
    long long int initialH = h;
    long long int initialW = w;

    while (initialH < n) {
        ++counter;
        initialH *= 2;
    }

    while (initialW < m) {
        ++counter;
        initialW *= 2;
    }

    long long int rotatedCounter = 0;
    long long int rotatedH = h;
    long long int rotatedW = w;

    while (rotatedH < m)
    {
        ++rotatedCounter;
        rotatedH *= 2;
    }

    while (rotatedW < n)
    {
        ++rotatedCounter;
        rotatedW *= 2;
    }

    return min(counter, rotatedCounter);
}

void test(const long long int n, const long long int m, const long long int h, const long long int w, long long int res, int testCounter) {
    cout << "Test " << testCounter << ", n = " << n << ", m = " << m << ", h = " << h << ", w = " << w << endl;
    ;

    long long int locRes = wrap(n, m, h, w);
    if (locRes == res)
    {
        cout << "Test " << testCounter << " OK, locRes = " << locRes << ", Res = " << res << endl;
    }
    else {
        cout << "Test " << testCounter << " WRONG, locRes = " << locRes << ", Res = " << res << endl;
    }
}

int main()
{
#ifdef LOCAL
    ifstream inputFile("test.txt");
    //объявить те же переменные, что и в основной части
    long long int n, m, h, w, res;
    int testCounter = 0;

    while (inputFile >> n >> m >> h >> w >> res)
    {
        ++testCounter;
        test(n, m, h, w, res, testCounter);
    }
#else
    ifstream inputFile("input.txt");
    long long int n, m, h, w;

    inputFile >> n >> m >> h >> w;

    long long int result = wrap(n, m, h, w);

    cout << result << endl;

#endif
    
return 0;
}