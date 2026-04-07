#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n, k;
    inputFile >> n >> k;

    deque<int> candidates;

    deque<int> digits;

    for (int i = 0; i < k; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        digits.push_back(bufInt);

        while (!candidates.empty() && candidates.back() > bufInt)
        {
            candidates.pop_back();
        }
        candidates.push_back(bufInt);
    }

    for (int i = k; i <= n; ++i)
    {
        int minimum = candidates.front();
        cout << minimum << endl;

        if (digits.front() == minimum)
        {
            candidates.pop_front();
        }

        digits.pop_front();

        int bufInt;
        inputFile >> bufInt;
        digits.push_back(bufInt);

        while (!candidates.empty() && candidates.back() > bufInt)
        {
            candidates.pop_back();
        }
        candidates.push_back(bufInt);
    }
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}