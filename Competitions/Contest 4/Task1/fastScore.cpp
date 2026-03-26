#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string& input){
    ifstream inputFile(input);
    int playersQuantity, notesQouantity;
    map<string, int> gameNotes;

    inputFile >> playersQuantity;

    string bufString;
    for (int i = 0; i < playersQuantity; ++i)
    {
        inputFile >> bufString;
        gameNotes[bufString] = 0;
    }

    inputFile >> notesQouantity;

    int leftPrev, leftCurr, rightPrev, rightCurr;
    string name;
    leftPrev = 0;
    rightPrev = 0;

    inputFile.ignore();


    for (int i = 0; i < notesQouantity; ++i)
    {
        getline(inputFile, bufString);
        istringstream iss(bufString);
        string leftStr, rightStr, name;
        getline(iss, leftStr, ':');
        getline(iss, rightStr, ' ');
        getline(iss, name);
        leftCurr = stoi(leftStr);
        rightCurr = stoi(rightStr);

        if (leftCurr > leftPrev) {
            gameNotes[name] += (leftCurr - leftPrev);
            leftPrev = leftCurr;
        }
        else if (rightCurr > rightPrev) {
            gameNotes[name] += (rightCurr - rightPrev);
            rightPrev = rightCurr;
        }
    }

    auto it = gameNotes.begin();
    auto itEnd = gameNotes.end();
    int maxSum = 0;
    string maxName;

    while (it != itEnd) {
        if (it->second > maxSum) {
            maxSum = it->second;
            maxName = it->first;
        }
        ++it;
    }

    cout << maxName << " " << maxSum << endl;
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