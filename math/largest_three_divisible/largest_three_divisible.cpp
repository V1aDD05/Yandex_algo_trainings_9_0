#include <iostream>
#include <vector>

/*
Сложность по времени: O(n), n - количество введённых цифр
Сложность по памяти: O(1)
*/

// функция формирования словарь для цифр
// и подсчёта суммы цифр
std::vector<int> countSumAndQuantity(int &sum)
{
    //будем хранить количество каждой из цифр во входных данных
    std::vector<int> digitsQuantity(10, 0);

    char bufChar;
    while (std::cin.get(bufChar) && bufChar != '\n')
    {
        int bufInt;
        bufInt = bufChar - '0';
        ++digitsQuantity[bufInt];
        sum += bufInt;
    }
    return digitsQuantity;
}

//функция вывода наибольшего числа, делящегося на три,
//формируемого из переданного набора цифр
void outputMaxInteger(std::vector<int> &digitsQuantity)
{
    // выводим наибольшую последовательность
    //(располагаем числа в порядке убывания)
    for (int i = 9; i >= 0; --i)
    {
        while (digitsQuantity[i] > 0)
        {
            std::cout << i;
            --digitsQuantity[i];
        }
    }
    std::cout << std::endl;
}

// функция составления из переданных цифр набора цифр,
// обеспечивающего формирование наибольшего кратного трём числа
void createMaxInteger(std::vector<int> &digitsQuantity, const int sum)
{
    /*если остаток от деления суммы на 3 равен 1,
    надо либо брать из последовательности наименьшую из имеющихся в наборе цифр,
    дающих при делении на 3 остаток 1; либо 2 наименьших цифры, дающих при делении на 3 остаток 2
    */
    if (sum % 3 == 1) {
        int removeCounter = 0;
        for (int suspect : {1,4,7}) {
            if (digitsQuantity[suspect] > 0) {
                --digitsQuantity[suspect];
                ++removeCounter;
                break;
            }
        }

        if (!removeCounter)
        {
            for (int suspect : {2, 5, 8})
            {
                while (digitsQuantity[suspect] > 0 && removeCounter < 2)
                {
                    --digitsQuantity[suspect];
                    ++removeCounter;
                }
            }
        }
    }
    /*если остаток от деления суммы на 3 равен 1,
    надо либо брать из полседовательности наименьшую из имеющихся в наборе цифр,
    дающих при делении на 3 остаток 2; либо 2 наименьших цифры, дающих при делении на 3 остаток 1
    */
    else if (sum % 3 == 2) {
        int removeCounter = 0;
        for (int suspect : {2, 5, 8})
        {
            if (digitsQuantity[suspect] > 0)
            {
                --digitsQuantity[suspect];
                ++removeCounter;
                break;
            }
        }

        if (!removeCounter)
        {
            int removeCounter = 0;
            for (int suspect : {1, 4, 7})
            {
                while (digitsQuantity[suspect] > 0 && removeCounter < 2)
                {
                    --digitsQuantity[suspect];
                    ++removeCounter;
                }
            }
        }
    }
}


int main()
{
    // будем считать сумму для последующего определения делимости
    int sum = 0;

    // формируем словарь для цифр (ключ - цифра, 
    // значение - количество появлений цифры во входных данных)
    // и считаем сумму цифр (для применения признаков делимости)
    std::vector<int> digitsQuantity = countSumAndQuantity(sum);

    // составляем из переданных цифр набора цифр, обеспечивающего
    // формирование наибольшего кратного трём числа
    createMaxInteger(digitsQuantity, sum);

    // выводим наибольшее число, делящееся на три,
    // формируемое из переданного набора цифр
    outputMaxInteger(digitsQuantity);

    return 0;
}