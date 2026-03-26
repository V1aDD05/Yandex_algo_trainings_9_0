#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int main()
{
    ifstream inputFile("input.txt");

    int buf;
    unordered_set<int> intSet;
    auto it = intSet.begin();

    while (inputFile >> buf)
    {
        it = intSet.find(buf);
        if (it == intSet.end())
        {
            cout << "NO" << endl;
            intSet.insert(buf);
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}