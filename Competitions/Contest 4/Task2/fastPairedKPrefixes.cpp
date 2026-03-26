#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

/* wrap(){

} */

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
    ifstream inputFile("input.txt");
    int quantity;
    string bufStr;
    map<string,int> stringSet;
    inputFile >> quantity;
    inputFile.ignore();
    int wordSize;

    for (int i = 0; i < quantity; ++i)
    {
        inputFile >> bufStr;
        if (!i)
        {
            wordSize = static_cast<int>(bufStr.size());
        }
        ++stringSet[bufStr];
    }

    int minIntersect = wordSize;
    bool isFirstFound = false;
    bool fullPair = false;
    auto it = stringSet.begin();
    auto itEnd = stringSet.end();
    string first, second;

    while (it != itEnd) {
        if (it->second % 2 != 0) {
            //если записываем первую строку из пары
            if (!isFirstFound)
            {
                first = it->first;
                isFirstFound = true;
            }
            else {
                second = it->first;
                isFirstFound = false;
                // посимвольное сравнение для определения minIntersect
                char firstChar;
                char secondChar;

                for (int k = 0; k < wordSize; ++k)
                {
                    firstChar = first[k];
                    secondChar = second[k];
                    if (firstChar != secondChar)
                    {
                        minIntersect = min(minIntersect, k);
                        break;
                    }
                }
            }
        }
        ++it;
    }

    if (isFirstFound) {
        minIntersect = 0;
    }

    cout << minIntersect << endl;

#endif

    return 0;
}