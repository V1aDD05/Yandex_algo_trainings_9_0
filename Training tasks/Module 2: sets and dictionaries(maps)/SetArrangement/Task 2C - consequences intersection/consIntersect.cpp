#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");

    unordered_set<int> first;
    auto it = first.begin();
    
    string firstline;
    getline(inputFile, firstline);
    istringstream iss(firstline);

    int bufInt;

    while (iss >> bufInt) {
        it = first.find(bufInt);
        if (it == first.end()) {
            first.insert(bufInt);
        }
    }

    vector<int> intersection;
    unordered_set<int> second;
    auto itSecond = second.begin();

    while (inputFile >> bufInt) {
        it = first.find(bufInt);
        if (it != first.end()) {
            itSecond = second.find(bufInt);
            if (itSecond == second.end()) {
                intersection.push_back(bufInt);
                second.insert(bufInt);
            }
        }
    }

    auto vecBegin = intersection.begin();
    auto vecEnd = intersection.end();

    sort(vecBegin, vecEnd);

    ofstream outputFile("output.txt");

    bool isFirst = true;
    for (auto member : intersection)
    {
        if (!isFirst) {
            outputFile << " ";
        }
        isFirst = false;
        outputFile << member;
    }
    outputFile << endl;

    return 0;
}