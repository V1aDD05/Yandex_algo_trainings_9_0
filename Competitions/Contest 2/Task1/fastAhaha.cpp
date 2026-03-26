/*
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
*/
#include <bits/stdc++.h>

using namespace std;

//#define LOCAL

int wrap(int length, const string& girlStroke) {

    int laughCounter = 0;

    int maxLength = 0;
    bool isInside = false;
    bool isA = false;
    bool wasA = false;
    bool wasH = false;
    bool duplication = false;
    size_t strokeLength = girlStroke.size();
    int currentSize = 0;

    for (size_t i = 0; i < strokeLength; ++i)
    {
        char bufChar = girlStroke[i];
        if (!isInside) {
            if (bufChar == 'a' || bufChar == 'h')
            {
                isInside = true;
                laughCounter = 1;
                if (bufChar == 'a') {
                    isA = true;
                    wasA = true;
                }
                else {
                    isA = false;
                    wasH = true;
                }
            }
            continue;
        }
        else {
            if (isA) {
                if (bufChar == 'h') {
                    ++laughCounter;
                    isA = false;
                    wasH = true;
                    duplication = false;
                }
                else {
                    if (bufChar == 'a')
                    {
                        if (wasH) {
                            maxLength = max(laughCounter, maxLength);
                        }
                        duplication = true;

                        laughCounter = 1;
                        isA = true;
                        wasA = true;
                        wasH = false;
                    }
                    else {
                        isInside = false;
                        maxLength = max(laughCounter, maxLength);
                        laughCounter = 0;
                        wasA = false;
                        wasH = false;
                    }
                    
                }
            }
            else {
                if (bufChar == 'a')
                {
                    ++laughCounter;
                    isA = true;
                    wasA = true;
                    wasH = true;
                    duplication = false;
                }
                else
                {
                    if (bufChar == 'h')
                    {
                        if (wasA)
                        {
                            maxLength = max(laughCounter, maxLength);
                        }
                        duplication = true;
                        laughCounter = 1;
                        isA = false;
                        wasA = false;
                    }
                    else {
                        isInside = false;
                        maxLength = max(laughCounter, maxLength);
                        laughCounter = 0;
                        wasA = false;
                        wasH = false;
                    }
                    
                }
            }
        }
    }
    if (isInside) {

        if ((wasA && wasH) || (wasA && laughCounter == 1 && !duplication) || (wasH && laughCounter == 1 && !duplication))
        {
            maxLength = max(laughCounter, maxLength);
        }
    }

    return maxLength;
}

void test(const int testLength, const string &testGirlStroke, const int correctRes, const int testCounter) {
    cout << "testLength = " << testLength << ", testGirlStroke = {" << testGirlStroke << "}" << endl;
    int testRes = wrap(testLength, testGirlStroke);

    if (testRes == correctRes)
    {
        cout << "TEST " << testCounter << " OK, testRes = " << testRes << ", correctRes = " << correctRes << endl;
    }
    else
    {
        cout << "TEST WRONG, testRes = " << testRes << ", correctRes = " << correctRes << endl;
    }
}

int main()
{
#ifdef LOCAL
    // TEST
    /*
    test(5, "ahaha", 5, 1);
    test(24, "ahahrunawayahahsofasthah", 4, 2);
    test(10, "ahahaahaha", 5, 3);
    test(1, "a", 1, 4);
    test(1, "h", 1, 5);
    test(1, "b", 0, 6);
    test(2, "aa", 0, 7);
    test(2, "hh", 0, 8);
    test(2, "ah", 2, 9);
    test(4, "ahaa", 3, 10);
    test(7, "abacaba", 1, 11);
    */
    ifstream testFile("test.txt");
    int length;
    string girlStroke;
    int result;
    int counter = 0;
    while (testFile >> length >> girlStroke >> result)
    {
        ++counter;
        test(length, girlStroke, result, counter);
    }

#else
    ifstream inputFile("input.txt");

    int length;
    inputFile >> length;

    inputFile.ignore();

    string girlStroke;
    getline(inputFile, girlStroke);

    int result = wrap(length, girlStroke);
    cout << result << endl;

#endif

    return 0;
}