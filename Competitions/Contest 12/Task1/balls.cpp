#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    int n;
    inputFile >> n;

    int buf;
    int delCounter = 0; //счётчик удаляемых
    int rowCounter = 0;

    const int rowMin = 3;

    stack<pair<int, int>> ballsOrder;

    for (int i = 0; i < n; ++i)
    {
        inputFile >> buf;

        if (!ballsOrder.empty() && buf == ballsOrder.top().first)
        {
            ++rowCounter;
            ballsOrder.push({buf, rowCounter});
        }
        else {
            //стирание ряда одинаковых, инкрементация счётчика удалённых
            if (rowCounter >= rowMin)
            {
                for (int j = 0; j < rowCounter; ++j)
                {
                    ++delCounter;
                    ballsOrder.pop();
                }
            }

            //если buf имеет тот же тип, что и верхний из оставшихся шариков,
            //продолжаем серию шариков верхнего типа. Иначе начинаем заново
            if (ballsOrder.empty() || !ballsOrder.empty() && ballsOrder.top().first != buf)
            {
                rowCounter = 1;
            }
            else if (!ballsOrder.empty() && ballsOrder.top().first == buf)
            {
                rowCounter = ballsOrder.top().second + 1;
            }
            ballsOrder.push({buf, rowCounter});
        }
    }

    // обработка случая, когда 3 и более одинаковых шариков шли до конца набора
    if (rowCounter >= rowMin)
    {
        for (int j = 0; j < rowCounter; ++j)
        {
            ++delCounter;
            ballsOrder.pop();
        }
    }

    cout << delCounter << endl;  

}

int main()
{
#ifdef LOCAL
    string test;
    int n = 3;
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