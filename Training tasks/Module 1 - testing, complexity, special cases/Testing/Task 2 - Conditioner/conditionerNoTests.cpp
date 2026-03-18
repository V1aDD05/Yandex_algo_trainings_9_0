#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int wrap(const int troom, const int tcond, const string &mode)
{
    if (mode == "freeze")
    {
        if (troom <= tcond)
        {
            return troom;
        }
        else
        {
            return tcond;
        }
    }
    if (mode == "heat")
    {
        if (troom >= tcond)
        {
            return troom;
        }
        else
        {
            return tcond;
        }
    }
    if (mode == "auto")
    {
        return tcond;
    }
    if (mode == "fan")
    {
        return troom;
    }
}

int main()
{
    ifstream inputFile("input.txt");
    int troom, tcond;
    string mode;

    inputFile >> troom >> tcond;

    char inputChar;
    inputFile.get(inputChar);

    getline(inputFile, mode);

    int finalTemp = wrap(troom, tcond, mode);

    cout << finalTemp << endl;

    return 0;
}