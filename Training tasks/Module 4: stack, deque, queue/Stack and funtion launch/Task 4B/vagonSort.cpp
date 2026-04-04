#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n;
    inputFile >> n;

    //true - вагон в тупике, false - нет
    map<int,bool> vagonMap;

    queue<int> firstLine;

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        inputFile >> bufInt;
        //обозначаем, что вагоны не в тупике
        vagonMap[bufInt] = false;
        firstLine.push(bufInt);
    }

    stack<int> deadEnd;

    bool ability = true;

    // пользуемся тем, что вагоны в map отсортированы по возрастанию
    for (auto &vagon : vagonMap)
    {
        if (vagon.second == true)
        {
            if (deadEnd.top() == vagon.first)
            {
                deadEnd.pop();
                vagonMap[vagon.first] = false;
                vagonMap.erase(vagon.first);
            }
            else
            {
                ability = false;
                break;
            }
        }
        else
        {
            while (vagon.second == false) {
                vagonMap[firstLine.front()] = true;
                deadEnd.push(firstLine.front());
                firstLine.pop();
            }
            deadEnd.pop();
            vagonMap[vagon.first] = false;
        }
    }

    if (ability)
    {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}