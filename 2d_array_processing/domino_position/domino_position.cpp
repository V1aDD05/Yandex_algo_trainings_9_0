#include <iostream>
#include <vector>

/*
Сложность по времени: O(n*m), `n` и `m` - размеры поля
Сложность по памяти: O(n*m)
*/

// функция заполнения поля (вектора строк) по воходным значениям
// (с добавлением столбца справа и строки снизу, чтобы
// в дальнейшем упростить обработку поля)
std::vector<std::string> fillGrid(const int n, const int m)
{
    std::vector<std::string> dominoGrid;
    dominoGrid.reserve(n);

    // добавим строку снизу и столбец справа из '#'
    // и не будем рассматривать частные случаи

    for (int i = 0; i < n; ++i)
    {
        std::string bufString;
        std::cin >> bufString;
        bufString += '#';
        dominoGrid.push_back(bufString);
    }
    std::string bufString(m + 1, '#');
    dominoGrid.push_back(bufString);

    return dominoGrid;
}

//функция определения количества различных способов расположения доминошки
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
    //считываем размеры поля
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();

    //заполняем поле входными данными
    std::vector<std::string> dominoGrid = fillGrid(n, m);

    //считаем и выводим количесвто различных расположений доминошки
    std::cout << numberOfPlacements(dominoGrid) << std::endl;

    return 0;
}