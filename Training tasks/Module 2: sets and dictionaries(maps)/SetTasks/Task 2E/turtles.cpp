#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string&  input){
    ifstream inputFile(input);

    int turtlesQuantity;
    int ai, bi;
    inputFile >> turtlesQuantity;

    //будем хранить в множестве значения ai
    set<int> turtlesOrder;
    auto it = turtlesOrder.begin();

    for (int i = 0; i < turtlesQuantity; ++i)
    {
        inputFile >> ai >> bi;
        //проверяем, что числа неотрицательные и в сумме дают количество минус одна (текущая) черепаха
        if (ai >= 0 && bi >= 0 && (ai + bi) == (turtlesQuantity - 1)) {
            it = turtlesOrder.find(ai);
            //сохраняем только те ai, которых ещё не было
            //(две черепахи не могут быть на одном месте)
            if (it == turtlesOrder.end()) {
                turtlesOrder.insert(ai);
            }
        }
    }

    int maxTrue = static_cast<int>(turtlesOrder.size());
    cout << maxTrue << endl;
}

// void test(){}

int main()
{
#ifdef LOCAL
    ifstream inputFile("test.txt");
    // объявить те же переменные, что и в основной части

    while ()
    {
        test();
    }
#else
    string input = "input.txt";
    wrap(input);
    
#endif

    return 0;
}