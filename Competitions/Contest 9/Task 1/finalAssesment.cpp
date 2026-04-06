#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    //unordered_map<char, int> alphabet;

    char bufChar;
    char minChar = 'A';

    int prefSum = 0;
    int counter = 0;

    while (inputFile.get(bufChar) && bufChar != '\n')
    {
        //++alphabet[char];
        ++counter;
        prefSum += (bufChar - 'A');
        if (bufChar - 'A' > minChar - 'A')
        {
            minChar = bufChar;
        }
    }

    double middle = static_cast<double>(prefSum) / counter;

    int round;
    double diff = abs(middle - prefSum / counter);

    if ((diff - 0.5) < 1e-6 )
    {
        round = prefSum / counter;
    }
    else {
        round = (prefSum / counter) + 1;
    }

    char midChar = static_cast<char>('A' + round);

    char result;
    if (midChar + 1 - 'A' < minChar - 'A')
    {
        result = static_cast<char>(minChar - 1);
    }
    else {
        result = midChar;
    }

    cout << result << endl;
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

    /*
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
    */
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}