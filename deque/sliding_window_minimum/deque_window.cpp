#include <iostream>
#include <deque>

using namespace std;

void fillWindow(std::deque<int> &candidates, std::deque<int> &digits, std::istream &in)
{
    int bufInt;
    in >> bufInt;
    digits.push_back(bufInt);

    while (!candidates.empty() && candidates.back() > bufInt)
    {
        candidates.pop_back();
    }
    candidates.push_back(bufInt);
}

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
    int n, k;
    std::cin >> n >> k;

    std::deque<int> candidates;

    std::deque<int> digits;

    // заполняем окно, пока не дойдём до k-го элемента
    for (int i = 0; i < k - 1; ++i)
    {
        fillWindow(candidates, digits, std::cin);
    }

    // теперь определяем формируем текущее окно (сдвигаемся при необходимости),
    // определяем для него минимум
    for (int i = k - 1; i < n; ++i)
    {
        fillWindow(candidates, digits, std::cin);
        findMinimum(candidates, digits);
    }
    return 0;
}