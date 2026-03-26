#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

string concatStr(string &part){
    size_t partSize = part.size();
    int beginChars;
    int endChars;
    int beginCounter = 0;
    int endCounter = 0;

    if (part[0] == 39) {
        int i = 0;
        while (part[i] == 39) {
            ++beginCounter;
            ++i;
        }
    }
    beginChars = 2*beginCounter;

    if (part[partSize - 1] == 39)
    {
        int j = partSize - 1;
        while (part[j] == 39)
        {
            ++endCounter;
            --j;
        }
    }
    endChars = static_cast<int>(partSize) - 1 - 2*endCounter;
    int len = endChars - beginChars + 1;
    string result = part.substr(beginChars, len);
    return result;
}

string wrap(const vector<string> &strVec)
{
    size_t vecSize = strVec.size();
    string result;
    string part;
    string buf;
    for (size_t i = 0; i < vecSize; ++i)
    {
        part = strVec[i];
        buf = concatStr(part);
        result += buf;
    }

    return result;
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
    ifstream inputFile("input.txt");
    vector<string> strVec;
    char inputChar;
    string bufStr;

    while (inputFile.get(inputChar) && inputChar != '\n') {
        if (inputChar != ' ') {
            bufStr.push_back(inputChar);
        }
        else {
            strVec.push_back(bufStr);
            bufStr.clear();
        }
    }
    strVec.push_back(bufStr);

    string result = wrap(strVec);

    cout << result << endl;
#endif

    return 0;
}