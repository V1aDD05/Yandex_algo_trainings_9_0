#include <iostream>
#include <string>

int detectTemperature(const int troom, const int tcond, const std::string &mode)
{
    int tResult;
    if (mode == "freeze")
    {
        if (troom <= tcond)
        {
            tResult = troom;
        }
        else
        {
            tResult = tcond;
        }
    }

    else if (mode == "heat")
    {
        if (troom >= tcond)
        {
            tResult = troom;
        }
        else
        {
            tResult = tcond;
        }
    }

    else if (mode == "auto")
    {
        tResult = tcond;
    }

    else if (mode == "fan")
    {
        tResult = troom;
    }

    return tResult;
}

int main()
{
    int troom, tcond;
    std::cin >> troom >> tcond;
    std::cin.ignore();

    std::string mode;
    std::cin >> mode;

    std::cout << detectTemperature(troom, tcond, mode) << std::endl;

    return 0;
}