#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    vector<int> digitsQuantity(10,0);

    char bufChar;
    int bufInt;
    int sum = 0;

    while (inputFile.get(bufChar) && bufChar != '\n')
    {
        bufInt = bufChar - '0';
        ++digitsQuantity[bufInt];
        sum += bufInt;
    }

    if (sum % 3 == 1) {
        bool isRemoved = false;
        for (int suspect : {1,4,7}) {
            if (digitsQuantity[suspect] > 0) {
                --digitsQuantity[suspect];
                isRemoved = true;
                break;
            }
        }

        if (!isRemoved) {
            int removeCounter = 0;
            for (int suspect : {2, 5, 8})
            {
                while (digitsQuantity[suspect] > 0 && removeCounter < 2)
                {
                    --digitsQuantity[suspect];
                    ++removeCounter;
                }
            }
        }
    }
    else if (sum % 3 == 2) {
        bool isRemoved = false;
        for (int suspect : {2, 5, 8})
        {
            if (digitsQuantity[suspect] > 0)
            {
                --digitsQuantity[suspect];
                isRemoved = true;
                break;
            }
        }

        if (!isRemoved)
        {
            int removeCounter = 0;
            for (int suspect : {1, 4, 7})
            {
                while (digitsQuantity[suspect] > 0 && removeCounter < 2)
                {
                    --digitsQuantity[suspect];
                    ++removeCounter;
                }
            }
        }
    }

    for (int i = 9; i >=0; --i) {
        while (digitsQuantity[i] > 0) {
            cout << i;
            --digitsQuantity[i];
        }
    }
    cout << endl;
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