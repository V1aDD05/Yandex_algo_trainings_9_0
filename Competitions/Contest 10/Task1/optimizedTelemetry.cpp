#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n, m, k;
    inputFile >> n >> m >> k;
    inputFile.ignore();

    vector<string> queueVec(n);
    int queuePtr = 0;

    string buffer;

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

            int bufQueueSize = static_cast<int>(queueVec[queuePtr].size());
            int maxStart = max(0, bufQueueSize - k);

            buffer.append(queueVec[queuePtr], maxStart, bufQueueSize - maxStart);
        }
        else if (line == "Paste")
        {
            size_t bufferSize = buffer.size();
            queueVec[queuePtr].append(buffer);
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

        cout << queueVec[queuePtr].substr(max(0, static_cast<int>(queueVec[queuePtr].size()) - k)) << endl;

    }
    else {
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