#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string& input){
    ifstream inputFile(input);

    map<string, string> synDict;

    int quantity;
    inputFile >> quantity;

    string first, second;
    
    for (int i = 0; i < quantity; ++i)
    {
        inputFile >> first >> second;
        synDict[first] = second;
        synDict[second] = first;
    }
    
    inputFile >> first;
    second = synDict[first];
    cout << second << endl;
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