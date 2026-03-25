#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

tuple<int, int, vector<string>, vector<string>> wrap(string &input)
{

    ifstream inputFile(input);

    string bufString;
    int studentsQuantity;
    int langQuantity;

    unordered_map<string, int> langMap;

    inputFile >> studentsQuantity;

    for (int i = 0; i < studentsQuantity; ++i)
    {
        inputFile >> langQuantity;
        for (int j = 0; j < langQuantity; ++j)
        {
            inputFile >> bufString;
            ++langMap[bufString];
        }
    }

    //ощих языков, уникальных языков, список общих, список уникальных

    int commonLang, uniqueLang;
    vector<string> commonLangVec, uniqueLangVec;

    commonLang = 0;
    uniqueLang = 0;

    for (const auto &pair : langMap) {
        if (pair.second == studentsQuantity) {
            ++commonLang;
            commonLangVec.push_back(pair.first);
        }
        uniqueLangVec.push_back(pair.first);
    }

    uniqueLang = static_cast<int>(uniqueLangVec.size());

    return make_tuple(commonLang, uniqueLang, commonLangVec, uniqueLangVec);
}

    // void test(){}

int main()
{
#ifdef LOCAL
    string test "test.txt";

    tuple<int, int, vector<string>, vector<string>> result = wrap(test);

    cout << get<0>(result) << endl;
    for (auto commLangs : get<2>(result))
    {
        cout << commLangs << endl;
    }
    cout << get<1>(result) << endl;
    for (auto uniqueLangs : get<3>(result))
    {
        cout << uniqueLangs << endl;
    }

#else
    string input = "input.txt";
    tuple<int, int, vector<string>, vector<string>> result = wrap(input);

    cout << get<0>(result) << endl;
    for (auto commLangs : get<2>(result)) {
        cout << commLangs << endl;
    }
    cout << get<1>(result) << endl;
    for (auto uniqueLangs : get<3>(result))
    {
        cout << uniqueLangs << endl;
    }
#endif

    return 0;
}