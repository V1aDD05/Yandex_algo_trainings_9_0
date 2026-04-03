#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    map<pair<int, int>, int> ceilMap;

    int horSum = 0;
    int verSum = 0;
    ceilMap[{horSum, verSum}] = 1;

    char bufChar;

    int counter = 0;

    while (inputFile.get(bufChar) && bufChar != '\n')
    {
        if (bufChar == 'U')
        {
            ++verSum;
            
        }
        else if (bufChar == 'L')
        {
            --horSum;
        }
        else if (bufChar == 'D')
        {
            --verSum;
        }
        else if (bufChar == 'R')
        {
            ++horSum;
        }

        ++ceilMap[{horSum, verSum}];
        if (ceilMap[{horSum, verSum}] == 2)
        {
            ++counter;
        }
    }
    cout << counter << endl;
}

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
    /*
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