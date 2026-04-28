#include <iostream>
#include <algorithm>    //std::min

/*
Сложность по времени: O(log([n*m]/[h*w])), где
`n` и `m` - исходные размеры простыни, `h` и `w` - длины сторон пакета

Сложность по памяти: O(1)
*/

// структура, хранящая исходные размеры простыни и пакета
struct InitialDimensions 
{
    //исходные размеры простыни
    long long int n;
    long long int m;

    //размеры пакета
    long long int h;
    long long int w;
};

//функция подсчёта количества складываний по одной из осей
int countFolds(const long long int sheetSide, long long int packetSide)
{
    int counter = 0;
    while (packetSide < sheetSide)
    {
        ++counter;
        packetSide *= 2;
    }
    return counter;
}

// функция определения минимального количества складываний
int minFold(const InitialDimensions &dimensions)
{
    /*
    важное замечание: складывания в двух различных направлениях независимы,
    поэтому результирующее количество складываний есть сумма складываний по двум осям
    */

    //подсчёт количества складываний в исходном положении
    int counter = countFolds(dimensions.n, dimensions.h) + countFolds(dimensions.m, dimensions.w);

    // подсчёт количества складываний при повороте простыни на 90 градусов

    int rotatedCounter = countFolds(dimensions.n, dimensions.w) + countFolds(dimensions.m, dimensions.h);

    //возвращаем меньшее количество складываний
    return std::min(counter, rotatedCounter);
}

int main()
{
    //считываем исходные размеры простыни и пакета
    long long int n, m, h, w;
    std::cin >> n >> m >> h >> w;

    //формируем хранящую их структуру
    InitialDimensions dimensions = {n, m, h, w};

    //определяем и выводим минимальное количество складываний
    std::cout << minFold(dimensions) << std::endl;

    return 0;
}