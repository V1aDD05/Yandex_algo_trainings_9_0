#include <iostream>
#include <fstream>
#include <cmath>
#include <utility>

using namespace std;

pair<int, string> wrap(int a, int b, int c)
{

    pair<int, string> output;

    if (c < 0)
    {
        output = make_pair(0, "NO SOLUTION");
    }
    else
    {
        if (!a)
        {
            if (b == c * c)
            {
                output = make_pair(0, "MANY SOLUTIONS");
            }
            else
            {
                output = make_pair(0, "NO SOLUTION");
            }
        }
        else
        {

            if ((c * c - b) % a == 0)
            {
                int x = (c * c - b) / a;
                if (a > 0)
                {
                    if (x >= (static_cast<double>(-b) / a))
                    {
                        output = make_pair(x, "ONE SOLUTION");
                    }
                    else
                    {
                        output = make_pair(0, "NO SOLUTION");
                    }
                }
                else
                {
                    if (x <= (static_cast<double>(-b) / a))
                    {
                        output = make_pair(x, "ONE SOLUTION");
                    }
                    else
                    {
                        output = make_pair(0, "NO SOLUTION");
                    }
                }
            }
            else
            {
                output = make_pair(0, "NO SOLUTION");
            }
        }
    }

    return output;
}

int main()
{
    ifstream inputFile("input.txt");
    int a, b, c;

    inputFile >> a >> b >> c;

    pair<int, string> result = wrap(a, b, c);

    if (result.second == "ONE SOLUTION")
    {
        cout << result.first << endl;
    }
    else if (result.second == "NO SOLUTION" || result.second == "MANY SOLUTIONS")
    {
        cout << result.second << endl;
    }

    return 0;
}