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
    map<string, int> stringSet;
    inputFile >> quantity;
    inputFile.ignore();

    // Заполнение - в худшем слуае O(nlogn)
    for (int i = 0; i < quantity; ++i)
    {
        inputFile >> bufStr;
        ++stringSet[bufStr];
    }


    bool isFirstFound = false;
    auto it = stringSet.begin();
    auto itEnd = stringSet.end();

    int wordSize = static_cast<int>(it->first.size());
    int minIntersect = wordSize;

    string first, second;

    // проходы по map. В худшем случае сложность O(n*L), L-длина слов
    // итерация по леентам для map - красно-чёрного дерева - имеет
    // амортизированную сложность O(n), а не O(nLogn)

    // применяем map, поэтому строки отсортированы, поэтому лучше сравнивать
    // ближайшие друг к другу с учётом неётности (см. ниже)
    while (it != itEnd)
    {
        // если колиество повторений чётное, такие строки рассматривать не нужно:
        // тогда эти строки будут попарно совпадать по всем символам
        if (it->second % 2 != 0)
        {
            // если записываем первую строку из пары
            if (!isFirstFound)
            {
                first = it->first;
                isFirstFound = true;
            }
            else
            {
                second = it->first;
                isFirstFound = false;
                // посимвольное сравнение для определения minIntersect
                int commonPrefiLength = 0;

                while (commonPrefiLength < wordSize && first[commonPrefiLength] == second[commonPrefiLength])
                {
                    ++commonPrefiLength;
                }
                minIntersect = min(commonPrefiLength, minIntersect);
            }
        }
        ++it;
    }

    if (isFirstFound)
    {
        minIntersect = 0;
    }

    cout << minIntersect << endl;

#endif

    return 0;
}