#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n, k;
    inputFile >> n >> k;

    vector<int> trees;
    trees.reserve(n);

    for (int i = 0; i < n; ++i) {
        int bufInt;
        inputFile >> bufInt;
        trees.push_back(bufInt);
    }

    int right = 0;

    unordered_map<int, int> treesQuantity;

    int minLength = INT_MAX;
    pair<int, int> minSection;

    //либо так: двигаем левый указатель по 1

    for (int left = 0; left < n; ++left)
    {   
        //двигаем вправо, пока хотя бы какого-то вида деревьев 0
        while (right < n && treesQuantity.size() < k)
        {
            ++treesQuantity[trees[right]];
            ++right;
        }
        //двигаем влево по шагу, пока одного вида дерева не станет 0
        if (treesQuantity.size() == k)
        {
            //вычисляем значение отрезка и обновляем ()при необходимости
            //right уже не следующей позиции, поэтому не делаем +1
            int bufLength = right - left;
            if (bufLength < minLength)
            {
                minLength = bufLength;
                minSection.first = left;
                // right уже не следующей позиции, поэтому делаем -1
                minSection.second = right - 1;
            }
            --treesQuantity[trees[left]];
            if (treesQuantity[trees[left]] == 0)
            {
                treesQuantity.erase(trees[left]);
            }
        }
    }

    // либо так: двигаем левый указатель до момента несоответствия условию
    /*
    while (right < n)
    {
        //двигаем вправо, пока хотя бы какого-то вида деревьев 0
        ++treesQuantity[trees[right]];
        if (treesQuantity.size() < k) {
            ++right;
        }
        //двигаем влево, пока одного вида дерева не станет 0
        else {
            while (treesQuantity.size() == k) {
                //вычисляем значение отрезка и обновляем ()при необходимости
                //right ещё на текущей позиции, поэтому делаем +1
                int bufLength = right - left + 1;
                if (bufLength < minLength)
                {
                    minLength = bufLength;
                    minSection.first = left;
                    // right ещё на текущей позиции, поэтому не делаем -1
                    minSection.second = right;
                }
                --treesQuantity[trees[left]];
                if (treesQuantity[trees[left]] == 0) {
                    treesQuantity.erase(trees[left]);
                    ++left;
                    break;
                }
                ++left;
            }
            // right ещё на текущей позиции, двигаем не следующую
            ++right;
        }
    }
    */

    cout << minSection.first + 1 << " " << minSection.second + 1 << endl;
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