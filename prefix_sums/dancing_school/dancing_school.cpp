#include <iostream>
#include <string>
#include <unordered_map>

/* Идея: заводим переменную prefDiff, хранящую префиксную сумму:
    при обработке поля, содержащего информацию о девочке, инкрементируем prefDiff,
    о мальчике - декрементируем.
    Нам подходят все промежутки, первый элемент которых и первый элемент после окончания которых одниаковы.
    Таких промежутков для данного значения prefDiff будет k*(k-1)/2 (сумма арифметической прогрессии), где
    k - количество точек, в которых prefDiff имела рассматриваемое значение
    Для этого храним количество значений prefDiff в std::unordered_map<int, int>
*/

/*
Сложность по времени: O(N)
Сложность по памяти: O(N + K) = O(N), K - количество различных значений prefDiff <= N.
*/

//функция подсчёта и запоминания значений префиксной суммы
std::unordered_map<int, int> countQuantities(const std::string &order)
{
    size_t orderSize = order.size();

    
    std::unordered_map<int, int> quantity;

    quantity[0] = 1;
    int prefDiff = 0;

    for (size_t i = 0; i < orderSize; ++i)
    {
        char bufChar = order[i];
        if (bufChar == 'a')
        {
            ++prefDiff;
        }

        else if (bufChar == 'b')
        {
            --prefDiff;
        }
        ++quantity[prefDiff];
    }

    return quantity;
}

//функция подсчёта количества отрезков с равным числом мальчиков и девочек
long long int sumQuantities(const std::unordered_map<int, int> &quantity)
{
    long long int result = 0;

    for (auto summand : quantity)
    {
        result += static_cast<long long int>(summand.second) * (summand.second - 1) / 2;
    }

    return result;
}

int main()
{
    // вообще говоря, обойдёмся без этой переменной,
    // т.к. order.size() == n 
    int n;
    std::cin >> n;  

    //считываем строку с описанием выстроившихся учеников
    std::string order;
    std::cin >> order;

    //считаем перфиксную сумму (см. идею в верху файла) и запоминаем значения
    std::unordered_map<int, int> quantity = countQuantities(order);

    // считаем количество отрезков с равным числом мальчиков и девочек
    std::cout << sumQuantities(quantity) << std::endl;

    return 0;
}