#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n, m, k;
    inputFile >> n >> m >> k;
    inputFile.ignore();

    vector<vector<char>> queueVec(n);
    int queuePtr = 0;

    string buffer;
    buffer.clear();

    for (int i = 0; i < m; ++i)
    {
        string line;
        getline(inputFile, line);

        if (line == "Next")
        {
            ++queuePtr;
            queuePtr = queuePtr % n;
        }
        else if (line == "Copy")
        {
            buffer.clear();
            if (!queueVec[queuePtr].empty())
            {
                int bufQueueSize = static_cast<int>(queueVec[queuePtr].size());
                int maxStart = max(0, bufQueueSize - k);

                for (int i = maxStart; i < bufQueueSize; ++i)
                {
                    buffer.push_back(queueVec[queuePtr][i]);
                }
            }
        }
        else if (line == "Paste")
        {
            size_t bufferSize = buffer.size();
            for (size_t i = 0; i < bufferSize; ++i)
            {
                queueVec[queuePtr].push_back(buffer[i]);
            }
        }
        else if (line == "Backspace")
        {
            if (!queueVec[queuePtr].empty())
            {
                queueVec[queuePtr].pop_back();
            }
        }
        else
        {
            char bufChar = line[0];
            queueVec[queuePtr].push_back(bufChar);
        }
    }

    if (!queueVec[queuePtr].empty())
    {
        int bufQueueSize = static_cast<int>(queueVec[queuePtr].size());
        int maxStart = max(0, bufQueueSize - k);

        for (int i = maxStart; i < bufQueueSize; ++i)
        {
            cout << queueVec[queuePtr][i];
        }
        cout << endl;
    }
    else
    {
        cout << "Empty" << endl;
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

    // 8
    test = "test8.txt";
    cout << "****************" << endl;
    cout << "       TEST 8" << endl;
    cout << "****************" << endl;
    wrap(test);
    cout << endl;
    cout << endl;

    // 9
    test = "test9.txt";
    cout << "****************" << endl;
    cout << "       TEST 9" << endl;
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