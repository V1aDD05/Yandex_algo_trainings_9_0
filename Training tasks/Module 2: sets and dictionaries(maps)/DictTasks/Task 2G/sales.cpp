#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string &input)
{
    ifstream inputFile(input);

    //ничего не сказано про размер данных,
    //тесты контеста с int не проходят
    map<string, map<string, long int>> dataBase;

    string bufStr;
    string customer;
    string subject;
    long int subQuantity;
    while (getline(inputFile, bufStr))
    {
        istringstream iss(bufStr);
        iss >> customer >> subject >> subQuantity;
        dataBase[customer][subject] += subQuantity;
    }

    for (const auto &person : dataBase)
    {
        cout << person.first << ":" << endl;
        for (const auto &product : person.second)
        {
            //защита от дурака, контест это не проверяет 
            if (product.second != 0)
            {
                cout << product.first << " " << product.second << endl;
            }
        }
    }
}

// void test(){}

int main()
{
#ifdef LOCAL
    string test;
    // объявить те же переменные, что и в основной части

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
#else
    string input = "input.txt";
    wrap(input);

#endif

    return 0;
}