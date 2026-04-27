#include <iostream>
#include <vector>

/*
Сложность по времени: O(n), n - суммарное количество памятников
Сложность по памяти: O(n).
*/

//функция формирования вектора с расстояниями
//от начала улицы до i-го памятника
std::vector<int> formDistancesVec(const int n)
{
    std::vector<int> distances;
    distances.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;
        distances.push_back(bufInt);
    }
    return distances;
}

//функция определения количества расположений мальчиков в соответствии с условием
long long int countCases(const int r, const std::vector<int> &distances)
{
    //"указатель" правой границы подотрезка
    int right = 0;

    //количество памятников
    int n = static_cast<int>(distances.size());

    //счётчик возможных случаев
    long long int counter = 0;

    //"указатель" левой границы подотрезка будем 
    //двигать на 1 вправо во внешнем цикле
    for (int left = 0; left < n - 1; ++left)
    {
        //нам не нужно рассматривать вообще все варианты: если right на правой
        //границе, а left пододвинулось к right на расстояние, меньшее r.
        //двигать left далее смысла не имеет
        if (right == n - 1 && distances[right] - distances[left] < r)
        {
            break;
        }

        // пока расстояние между left и right не больше r, сдвигаем right вправо
        while (distances[right] - distances[left] <= r && right < n - 1)
        {
            ++right;
        }

        // если нашлось такое right, что расстояние между left и right 
        // больше r, то и все позиции правее right также подходят
        if (distances[right] - distances[left] > r)
        {
            counter += static_cast<int>(n) - right;
        }
    }
}


int main()
{
    // считываем количество памятников и
    // максимальное расстояние, на котором мальчики могут увидеть друг друга
    int n, r;
    std::cin >> n >> r;

    // формируем вектора с расстояниями от начала улицы до i-го памятника
    std::vector<int> distances = formDistancesVec(n);

    // определяем и выводим количество расположений мальчиков
    // в соответствии с условием
    std::cout << countCases(r, distances) << std::endl;

    return 0;
}