#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

/* wrap(){

} */

// void test(){}

int main()
{
#ifdef LOCAL
    ifstream inputFile("test.txt");
    // объявить те же переменные, что и в основной части

    while ()
    {
        test();
    }
#else
    ifstream inputFile("input.txt");
    int n;
    inputFile >> n;

    //Для указанных данных переполнения не будет
    int prefSum = 0;

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        prefSum += bufInt;
        if (i)
        {
            cout << " ";
        }
        cout << prefSum;
    }

#endif

    return 0;
}