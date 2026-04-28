#include <iostream>
#include <deque>

/*
Сложность по времени: O(n), n - длина последовательности
Сложность по памяти: O(n + k), k - размер "окна"
*/

//функция заполнения "окна" на текущей итерации
void fillWindow(std::deque<int> &candidates, std::deque<int> &digits, std::istream &in)
{
    int bufInt;
    in >> bufInt;

    //добавляем число в конец окна
    digits.push_back(bufInt);

    //числа в последовательности кандидитов, большие данного,
    //перестают быть кандидатами
    while (!candidates.empty() && candidates.back() > bufInt)
    {
        candidates.pop_back();
    }
    candidates.push_back(bufInt);
}

//функция определения минимального числа в текущем положении окна
void findMinimum(std::deque<int> &candidates, std::deque<int> &digits)
{
    int minimum = candidates.front();
    std::cout << minimum << std::endl;

    if (digits.front() == minimum)
    {
        candidates.pop_front();
    }

    digits.pop_front();
}

int main()
{
    // считываем длины последовательности и "окна", соответственно
    int n, k;
    std::cin >> n >> k;

    //последовательность кандидатов на минимальное значение
    std::deque<int> candidates;

    //последовательность, хранящая числа в "окне"
    std::deque<int> digits;

    // заполняем окно, пока не дойдём до k-го элемента
    for (int i = 0; i < k - 1; ++i)
    {
        fillWindow(candidates, digits, std::cin);
    }

    // теперь формируем текущее окно (сдвигаемся при необходимости),
    // определяем для него минимум
    for (int i = k - 1; i < n; ++i)
    {
        fillWindow(candidates, digits, std::cin);
        findMinimum(candidates, digits);
    }
    return 0;
}