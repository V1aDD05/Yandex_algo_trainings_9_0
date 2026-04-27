#include <iostream>
#include <vector>


int bacteriaCount(const int n, const int m, std::istream& in)
{
    std::vector<std::vector<bool>> bacteriaCells(n+1, std::vector<bool>(m+1, false));

    int bacteriaCounter = 0;

    for (int i = 1; i < n+1; ++i)
    {
        for (int j = 1; j < m+1; ++j)
        {
            char bufChar;
            std::cin >> bufChar;
            if (bufChar == '#')
            {
                bacteriaCells[i][j] = true;
                if (bacteriaCells[i - 1][j] == false && bacteriaCells[i][j - 1] == false)
                {
                    ++bacteriaCounter;
                }
            }  
        }
        in.ignore();
    }
    return bacteriaCounter;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();
    std::cout << bacteriaCount(n, m, std::cin) << std::endl;

    return 0;
}