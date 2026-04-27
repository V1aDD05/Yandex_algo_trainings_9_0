#include <iostream>
#include <vector>

/*
Сложность по времени: O(N)
Сложность по памяти: O(3*N) = O(N).
*/

//функция вычисления суммарной высоты подъёмов на маршрутах
void sumRises(const int m, const std::vector<int> &prefSum, const std::vector<int> &suffSum)
{
    for (int i = 0; i < m; ++i)
    {
        // считываем точки маршрутов
        int start, finish;
        std::cin >> start >> finish;
        // ввод предполагает начало отсчёта с 1.
        // приводим к единому виду
        --start;
        --finish;

        int result;
        // в зависимости от направления движения берём нужную сумму
        if (finish >= start)
        {
            result = prefSum[finish] - prefSum[start];
        }
        else
        {
            result = suffSum[finish] - suffSum[start];
        }
        std::cout << result << std::endl;
    }
}

// функция вычисления префиксных сумм и заполнения вектора "rises" с координатами y
std::vector<int> countPrefSums(const int n, std::vector<int> &rises) 
{
    // префиксные суммы. Для i-ой точки i-ая сумма
    std::vector<int> prefSum(n);
    prefSum[0] = 0;

    // первые координаты считываем вне цикла,
    // чтобы в цикле считать сумму
    int yCurr;
    std::cin >> yCurr >> yCurr;
    rises.push_back(yCurr);

    for (int i = 1; i < n; ++i)
    {
        // считывание текущих координат
        std::cin >> yCurr >> yCurr;
        rises.push_back(yCurr);

        // считаем перепад высот
        int bufRise = rises[i] - rises[i - 1];
        // если положительный, прибавляем
        if (bufRise > 0)
        {
            prefSum[i] = prefSum[i - 1] + bufRise;
        }
        // если неположительный, берём предыдущее
        else
        {
            prefSum[i] = prefSum[i - 1];
        }
    }

    return prefSum;
}

//функция вычисления суффиксных сумм
std::vector<int> countSuffSums(const int n, const std::vector<int> &rises)
{
    // суффиксные суммы
    std::vector<int> suffSum(n);
    suffSum[n - 1] = 0;

    for (int j = n - 2; j >= 0; --j)
    {
        int bufRise = rises[j] - rises[j + 1];
        if (bufRise > 0)
        {
            suffSum[j] = suffSum[j + 1] + bufRise;
        }
        else
        {
            suffSum[j] = suffSum[j + 1];
        }
    }

    return suffSum;
}

int main()
{
    //считываем количество вершин
    int n;
    std::cin >> n;

    // координаты y - придётся хранить для подсчёта постфикс суммы
    std::vector<int> rises;
    rises.reserve(n);

    // вычисляем префиксные суммы и заполняем вектор "rises"
    //с координатами y
    std::vector<int> prefSum = countPrefSums(n, rises);

    // вычисляем суффиксные суммы
    std::vector<int> suffSum = countSuffSums(n, rises);

    //считываем количество трасс
    int m;
    std::cin >> m;

    // вычисляем и выводим суммарную высоту подъёмов на каждом из маршрутов
    sumRises(m, prefSum, suffSum);

    return 0;
}