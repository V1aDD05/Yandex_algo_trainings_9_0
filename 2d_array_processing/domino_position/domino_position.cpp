#include <iostream>
#include <vector>

int numberOfPlacements(const std::vector<std::string> &dominoGrid)
{
    int result = 0;
    size_t mapRaws = dominoGrid.size() - 1;
    size_t mapCols = dominoGrid[0].size() - 1;

    for (size_t i = 0; i < mapRaws; ++i){
        for (size_t j = 0; j < mapCols; ++j) {
            if (dominoGrid[i][j] == '.' && dominoGrid[i][j + 1] == '.')
            {
                ++result;
            }
            if (dominoGrid[i][j] == '.' && dominoGrid[i + 1][j] == '.')
            {
                ++result;
            }
        }
    }
    return result;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();

    std::vector<std::string> dominoGrid;
    dominoGrid.reserve(n);

    // добавим строку снизу и столбец справа из '#'
    //и не будем рассматривать частные случаи
    std::string bufString;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> bufString;
        bufString += '#';
        dominoGrid.push_back(bufString);
    }
    std::string bufString(m+1, '#');
    dominoGrid.push_back(bufString);

    int result = numberOfPlacements(dominoGrid);

    std::cout << result << std::endl;
    return 0;
}