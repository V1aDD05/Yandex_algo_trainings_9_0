#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");

    int buf;
    unordered_set<int> intSet;
    size_t uniqueCounter = 0;
    auto it = intSet.begin();

    while (inputFile >> buf)
    {
        it = intSet.find(buf);
        if (it == intSet.end())
        {
            ++uniqueCounter;
            intSet.insert(buf);
        }
    }

    cout << uniqueCounter << endl;

    return 0;
}