#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n;
    inputFile >> n;

    vector<int> tables(n);
    for (int i = 0; i < n; ++i) {
        int bufInt;
        inputFile >> bufInt;
        tables[i] = bufInt;
    }

    int left = 0;
    int right = n - 1;

    long long int leftSum = tables[0];
    long long int rightSum = 0;

    //можем сделать int, а не long long int, т.к. 
    //стремимся к минимальному различию, поэтому двигаем
    //в требуему сторону, поэтому различие не больше max(ai) = 10^9 
    int minAbs = INT_MAX;

    pair<int, int> minPos;

    bool isLeft = false;
    bool isRight = true;

    while (left < right) {
        //прибавляем сырки к изменившейся сумме
        if (isLeft) {
            leftSum += tables[left];
            isLeft = false;
        }
        else if (isRight) {
            rightSum += tables[right];
            isRight = false;
        }

        //определяем, даёт ли данное сочетание наименьшее различие
        if (abs(leftSum - rightSum) < minAbs) {
            minAbs = abs(leftSum - rightSum);
            minPos.first = left;
            minPos.second = right;
        }

        //определяем, куда дальше сдвигаться
        if (leftSum < rightSum) {
            ++left;
            isLeft = true;
        }
        else {
            --right;
            isRight = true;
        }
    }
    
    //по условию нумерация столов с 1
    ++minPos.first;
    ++minPos.second;
    cout << minAbs << " " << minPos.first << " " << minPos.second << endl;
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