#include <iostream>
#include <vector>

/*
Сложность по времени: O(n).
Сложность по памяти: O(1)
*/

void createMaxInteger(std::vector<int> &digitsQuantity, const int sum)
{
    /*если остаток от деления суммы на 3 равен 1,
    надо либо брать из полседовательности наименьшую из имеющихся в наборе цифр,
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
    //будем хранить количество каждой из цифр во входных данных
    std::vector<int> digitsQuantity(10, 0);

    char bufChar;
    int bufInt;
    //будем считать сумму для последующего определения делимости
    int sum = 0;

    while (std::cin.get(bufChar) && bufChar != '\n')
    {
        bufInt = bufChar - '0';
        ++digitsQuantity[bufInt];
        sum += bufInt;
    }

    createMaxInteger(digitsQuantity, sum);

    //выводим наибольшую последовательность
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

    return 0;
}