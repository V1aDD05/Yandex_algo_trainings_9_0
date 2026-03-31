#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n, r;
    inputFile >> n >> r;

    vector<int> distances(n);
    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        distances[i] = bufInt;
    }

    int left;
    int right = 0;
    long long int counter = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        left = i;

        if (right == n-1 && distances[right] - distances[left] < r) {
            break;
        }

        while (distances[right] - distances[left] <= r && right < n-1){
            ++right;
        }

        if (distances[right] - distances[left] > r) {
            counter += static_cast<int>(n) - right;
        }
    }

    cout << counter << endl;
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}