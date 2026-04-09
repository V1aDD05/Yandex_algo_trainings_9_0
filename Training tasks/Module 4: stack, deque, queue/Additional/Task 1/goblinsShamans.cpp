#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n;
    inputFile >> n;
    inputFile.ignore();

    deque<int> goblinsQueue;

    for (int i = 0; i < n; ++i)
    {
        string line;
        getline(inputFile, line);
        string intStr = "";
        size_t lineSize = line.size();
        if (line[0] == '+')
        {
            intStr = line.substr(2, lineSize);
            goblinsQueue.push_back(stoi(intStr));
        }
        else if (line[0] == '*'){
            intStr = line.substr(2, lineSize);

            size_t goblinsQueueSize = goblinsQueue.size();
            size_t insertPlace;
            if (goblinsQueueSize % 2 == 0)
            {
                insertPlace = goblinsQueueSize / 2;
            }
            else {
                insertPlace = goblinsQueueSize / 2 + 1;
            }
            auto it = goblinsQueue.begin() + insertPlace;
            goblinsQueue.insert(it, stoi(intStr));
        }
        else if (line[0] == '-') {
            cout << goblinsQueue[0] << endl;
            goblinsQueue.pop_front();
        }
    }
}

int main()
{
#ifdef LOCAL
    string test;
    int n = 6;
    for (int i = 1; i <= n; ++i)
    {
        test = "test" + to_string(i) + ".txt";
        cout << "****************" << endl;
        cout << "       TEST " << i << endl;
        cout << "****************" << endl;
        wrap(test);
        cout << endl;
        cout << endl;
    }
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}