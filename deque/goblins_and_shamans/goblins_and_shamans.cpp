#include <iostream>
#include <string>
#include <deque>

/*
Сложность по времени: O(n), n - количество гоблинов
Сложность по памяти: O(n)
*/

// функция проверки правильности порядка построения гоблинов
void checkOrder(const int n, std::istream &in)
{
    // во избежание дорогой операции insert для std::vector, сделали два std::deque: left и right
    std::deque<int> left;
    std::deque<int> right;

    /*идея: так как возможны регулярные вставки в середину последовательности,
    делаем два std::deque и выполняем вставку только на их края, балансируя два
    std::deque между собой: left < right; left + 1 >= right
    */

    
    for (int i = 0; i < n; ++i)
    {
        //считываем входной запрос
        std::string line;
        getline(in, line);

        size_t lineSize = line.size();
        //случай добавления обычного гоблина
        if (line[0] == '+')
        {
            right.push_back(stoi(line.substr(2, lineSize)));
            //балансировка
            if (right.size() > left.size())
            {
                left.push_back(right.front());
                right.pop_front();
            }
        }
        //случай добавления привилегированного гоблина
        else if (line[0] == '*')
        {
            left.push_back(stoi(line.substr(2, lineSize)));
            // балансировка
            if (left.size() > right.size() + 1)
            {
                right.push_front(left.back());
                left.pop_back();
            }
        }
        //случай, когда первый в очереди гоблин ушёл к шаманам
        else if (line[0] == '-')
        {
            std::cout << left[0] << std::endl;
            left.pop_front();
            // балансировка
            if (right.size() > left.size())
            {
                left.push_back(right.front());
                right.pop_front();
            }
        }
    }
}

int main()
{
    //считываем количество запросов к программе
    int n;
    std::cin >> n;
    std::cin.ignore();

    //проверяем правильность порядка построения гоблинов
    checkOrder(n, std::cin);

    return 0;
}