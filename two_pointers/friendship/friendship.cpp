#include <iostream>
#include <vector>
#include <utility> //std::pair
#include <algorithm>
#include <climits> //INT_MAX

/*
Сложность по времени: O(n), n - количество столов
Сложность по памяти: O(n)
*/

// структура, хранящая искомые параметры (результат соревнований)
struct CompetitionResult
{

    // минимальное значение `∣SDV​−SDM​∣`
    long long int minAbs;
    /*
    можем сделать minAbs переменной типа `int`, а не `long long int`, т.к.
    стремимся к минимальному различию, поэтому двигаем
    в требуемую сторону, поэтому различие не больше max(ai) = 10^9
    */

    // стол, у которого остановится Вася
    int leftPos;

    // стол, у которого остановится Маша
    int rightPos;

    CompetitionResult(const int n) : minAbs(INT_MAX), leftPos(0), rightPos(n - 1) {};
};

// функция заполнения информации о количестве сырков на столах
std::vector<int> fillTables(const int n)
{
    std::vector<int> tables;
    tables.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        tables.push_back(bufInt);
    }

    return tables;
}

// функция определения результатов соревнований
CompetitionResult simulateCompetitions(const int n, const std::vector<int> &tables)
{
    struct CompetitionStatus
    {
        // флаг направления движения на следующей итерации
        bool isLeft;

        // переменные, хранящие столы, у которых стоят участники
        int leftTable;
        int rightTable;

        // сумма съеденных Васей (слева направо) сырков
        long long int leftSum;

        // сумма съеденных Машей (справа налево) сырков
        long long int rightSum;

        CompetitionStatus(int leftStart, int rightTbl) : isLeft(false),
                                                         leftTable(0),
                                                         rightTable(rightTbl - 1),
                                                         leftSum(leftStart),
                                                         rightSum(0) {};
    };

    CompetitionStatus status(tables[0], n);

    CompetitionResult result(n);

    // применяем метод двух указателей (встречное движение)
    while (status.leftTable < status.rightTable)
    {
        // прибавляем сырки к изменившейся сумме
        if (status.isLeft)
        {
            status.leftSum += tables[status.leftTable];
        }
        else
        {
            status.rightSum += tables[status.rightTable];
        }

        // определяем, даёт ли данное сочетание наименьшее различие
        if (abs(status.leftSum - status.rightSum) < result.minAbs)
        {
            result.minAbs = std::abs(status.leftSum - status.rightSum);
            result.leftPos = status.leftTable;
            result.rightPos = status.rightTable;
        }

        // определяем, куда дальше сдвигаться
        if (status.leftSum < status.rightSum)
        {
            ++status.leftTable;
            status.isLeft = true;
        }
        else
        {
            --status.rightTable;
            status.isLeft = false;
        }
    }
    return result;
}

int main()
{
    int n;
    std::cin >> n;

    // записываем информацию о количестве сырков на столах
    std::vector<int> tables = fillTables(n);

    // определяем результат соревнований
    CompetitionResult result = simulateCompetitions(n, tables);

    // выводим результат, учитывая, что нумерация в условии начинается с 1
    std::cout << result.minAbs << " " << result.leftPos + 1 << " " << result.rightPos + 1 << std::endl;

    return 0;
}