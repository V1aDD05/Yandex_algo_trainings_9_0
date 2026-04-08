#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n, m;
    inputFile >> n >> m;
    vector<vector<bool>> bacteriaCells(n+1, vector<bool>(m+1, false));

    int bacteriaCounter = 0;

    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < m+1; ++j)
        {
            char bufChar;
            inputFile >> bufChar;
            if (bufChar == '#')
            {
                bacteriaCells[i][j] = true;

                if (bacteriaCells[i - 1][j] == false && bacteriaCells[i][j - 1] == false)
                {
                    ++bacteriaCounter;
                }
            }
        }
    }
    cout << bacteriaCounter << endl;
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