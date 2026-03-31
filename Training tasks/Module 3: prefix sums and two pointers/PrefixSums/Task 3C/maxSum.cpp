#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);
    int n;
    inputFile >> n;

    // Для указанных данных переполнения не будет

    long long int maxPoz = 0;
    int maxNeg = INT_MIN;

    //флаги наличия чисел того или иного типа 
    bool isPos = false;
    bool isNeg = false;
    bool isZeros = false;

    //флаги перехода от "+" к "-" и наоборот
    //по умолчани ювыставляем true - это соответствует логике программы 
    bool firstNeg = true;
    bool firstPos = true;

    //будем считать префиксную сумму (и в некоторых случаях - обнулять)
    long long int posPrefSum = 0;

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        inputFile >> bufInt;

        if (bufInt > 0)
        {
            isPos = true;
            // если перешли от "-", меняем флаги
            // и проверяем - если posPrefSum >= 0
            //(была положителной и поле суммирования с "-" - осталась положительной),
            //продолжаем суммировать, иначе начинаем сначала
            if (firstPos) {
                firstNeg = true;
                firstPos = false;
                if (posPrefSum < 0)
                {
                    posPrefSum = 0;
                }
            } 
            posPrefSum += bufInt;
        }
        //в принципе иеет смысл учитывать, если "+" еще не обнаружили
        else if (!isPos && bufInt == 0)
        {
            isZeros = true;
        }
        else if (bufInt < 0)
        {
            // в принципе иеет смысл учитывать, если "+" еще не обнаружили
            if (!isPos) {
                isNeg = true;
                //максимальная сумма отрезка "-" чисел - максимальное "-" число 
                maxNeg = max(maxNeg, bufInt);
            }
            else
            {
                // если перешли от "+", фиксируем полученное знаение posPrefSum
                if (firstNeg) {
                    maxPoz = max(maxPoz, posPrefSum);
                    firstNeg = false;
                    firstPos = true;
                }
                // если posPrefSum окажется по модулю больше отрезка отрицательных чисел,
                // то после суммирования с отрезком отрицательных чисел
                // posPrefSum всё ещё будет "+" и мы продолжим её наращивать (уже с "+" числами)
                posPrefSum += bufInt;
            }
        }
    }

    // если финальный элемент положительный, то в цикле не произодёт
    // сравнение значения его префиксной суммы с найденной до этого
    maxPoz = max(maxPoz, posPrefSum);

    long long int maxSum;

    //проверяем в порядке убывания
    if (isPos)
    {
        maxSum = maxPoz;
    }
    else if (isZeros)
    {
        maxSum = 0;
    }
    else if (isNeg)
    {
        maxSum = maxNeg;
    }

    cout << maxSum << endl;
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

    // 7
    test = "test7.txt";
    cout << "****************" << endl;
    cout << "       TEST 7" << endl;
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