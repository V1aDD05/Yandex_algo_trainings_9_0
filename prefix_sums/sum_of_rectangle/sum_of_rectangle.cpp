#include <iostream>
#include <vector>

/*
Сложность по времени: O(N * M + K), N и N - размеры матрицы, K - количество запросов 
Сложность по памяти: O(N * M).
*/

//функция вычисления матрицы построчных префиксных сумм
std::vector<std::vector<int>> countLineSums(const int n, const int m)
{
    std::vector<std::vector<int>> lineSums(n, std::vector<int>(m + 1));
    for (int i = 0; i < n; ++i)
    {
        lineSums[i][0] = 0;

        for (int j = 0; j < m; ++j)
        {
            int bufInt;
            std::cin >> bufInt;
            lineSums[i][j + 1] = lineSums[i][j] + bufInt;
        }
    }
    return lineSums;
}

// функция вычисления и вывода требуемых в запросах сумм прямоугольников
void countRequestSums(const int k, const std::vector<std::vector<int>> &lineSums)
{
    for (int i = 0; i < k; ++i)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        // по условию счёт элементов начинается с 1 -> приводим к одному виду
        --x1;
        --y1;
        --x2;
        --y2;

        int result = 0;

        for (int j = x1; j <= x2; ++j)
        {
            result += lineSums[j][y2 + 1] - lineSums[j][y1];
        }

        std::cout << result << std::endl;
    }
}

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    //вычисляем построчные префиксные суммы
    std::vector<std::vector<int>> lineSums = countLineSums(n,m);

    //вычисляем и выводим требуемые в запросах суммы
    countRequestSums(k, lineSums);

    return 0;
}