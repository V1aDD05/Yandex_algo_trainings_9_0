#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>    //std::sort

/*
Сложность по времени: O(n), n - суммарное количество чисел в двух наборах
Сложность по памяти: O(n)
*/

//функция формирования отсортированного вектора чисел из
//входной строки
std::vector<int> formSortedVector(const std::string line)
{
    std::istringstream iss(line);

    std::vector<int> bufVec;
    int bufInt;
    while (iss >> bufInt)
    {
        bufVec.push_back(bufInt);
    }
    std::sort(bufVec.begin(), bufVec.end());

    return bufVec;
}

// функция поиска и вывода одинаковых чисел в наборах
void findSame(const std::vector<int> &firstVec, const std::vector<int> &secondVec)
{
    size_t firstSize, secondSize;
    firstSize = firstVec.size();
    secondSize = secondVec.size();

    size_t k = firstSize + secondSize;

    //"указатели" рассматриваемых позиций в векторах
    int firstPointer = 0;
    int secondPointer = 0;

    //флаг, обозначающий первый вывод числа
    bool isFirst = true;

    for (size_t i = 0; i < k; ++i)
    {
        if (firstVec[firstPointer] == secondVec[secondPointer])
        {
            if (isFirst)
            {
                //если выводим первое число, пробел перед ним не ставим
                isFirst = false;
                std::cout << firstVec[firstPointer];
            }
            else
            {
                //вывод делаем здесь же, чтобы не хранить отдельно
                //найденные совпадающие числа
                std::cout << " " << firstVec[firstPointer];
            }
            ++firstPointer;
            ++secondPointer;

            // сразу два "указателя" инкрементировали,
            //поэтому и i должно увеличиться на 2: явно и по окончании итерации
            ++i;
        }
        // сдвигаемся по второму вектору, если первый прошли до конца
        // или если текущий элемент второго меньше текущего элемента первого
        else if (firstPointer == (firstSize - 1) || secondVec[secondPointer] < firstVec[firstPointer])
        {
            ++secondPointer;
        }
        //во всех остальных случаях двигаемся по первому вектору
        else
        {
            ++firstPointer;
        }
    }
    std::cout << std::endl;
}

int main()
{
    std::string line;

    // считываем первую строку и формируем из неё
    // отсортированный вектор чисел
    getline(std::cin, line);
    std::vector<int> firstVec = formSortedVector(line);

    // считываем вторую строку и формируем из неё
    // отсортированный вектор чисел
    getline(std::cin, line);
    std::vector<int> secondVec = formSortedVector(line);

    // поиск и вывод одинаковых чисел в наборах
    findSame(firstVec, secondVec);

    return 0;
}