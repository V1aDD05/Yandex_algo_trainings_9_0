#include <iostream>
#include <algorithm> //std::max
#include <climits>   //INT_MIN

/*
Сложность по времени: O(N)
Сложность по памяти: O(1).
*/

// структура, отражающая ситуацию при обработке чисел
struct SumsFlags
{
    // флаги наличия чисел того или иного типа
    bool isPos;
    bool isNeg;
    bool isZeros;

    // максимальная сумма отрезка "-" чисел - максимальное "-" число
    int maxNeg;

    // максимальная сумма отрезка положительных чисел
    long long int maxPoz;
};

//функция определения максимальной суммы подпоследовательностей
//положительных и отрицательных чисел
void countSums(const int n, SumsFlags &status)
{
    // флаги перехода от "+" к "-" и наоборот
    // по умолчани ювыставляем true - это соответствует логике программы
    bool firstNeg = true;
    bool firstPos = true;

    // будем считать префиксную сумму (и в некоторых случаях - обнулять)
    long long int posPrefSum = 0;

    for (int i = 0; i < n; ++i)
    {
        int bufInt;
        std::cin >> bufInt;

        if (bufInt > 0)
        {
            status.isPos = true;
            // если перешли от "-", меняем флаги
            // и проверяем - если posPrefSum >= 0
            //(была положительной и после суммирования с "-" - осталась положительной),
            // продолжаем суммировать, иначе начинаем сначала
            if (firstPos)
            {
                firstNeg = true;
                firstPos = false;
                if (posPrefSum < 0)
                {
                    posPrefSum = 0;
                }
            }
            posPrefSum += bufInt;
        }
        // в принципе имеет смысл учитывать, если "+" еще не обнаружили
        else if (!status.isPos && bufInt == 0)
        {
            status.isZeros = true;
        }
        else if (bufInt < 0)
        {
            // в принципе имеет смысл учитывать, если "+" еще не обнаружили
            if (!status.isPos)
            {
                status.isNeg = true;
                // максимальная сумма отрезка "-" чисел - максимальное "-" число
                status.maxNeg = std::max(status.maxNeg, bufInt);
            }
            else
            {
                // если перешли от "+", фиксируем полученное знаение posPrefSum
                if (firstNeg)
                {
                    status.maxPoz = std::max(status.maxPoz, posPrefSum);
                    firstNeg = false;
                    firstPos = true;
                }
                // если posPrefSum окажется по модулю больше суммы отрезка отрицательных чисел,
                // то после суммирования с отрезком отрицательных чисел
                // posPrefSum всё ещё будет "+" и мы продолжим её наращивать (уже с "+" числами)
                posPrefSum += bufInt;
            }
        }
    }

    // если финальный элемент положительный, то в цикле не произодёт
    // сравнение значения его префиксной суммы с найденной до этого
    status.maxPoz = std::max(status.maxPoz, posPrefSum);
}

//функция определения максимального значения из вычисленных
long long int findMaxSum(const SumsFlags &status)
{
    long long int maxSum;

    // проверяем в порядке убывания
    if (status.isPos)
    {
        maxSum = status.maxPoz;
    }
    else if (status.isZeros)
    {
        maxSum = 0;
    }
    else if (status.isNeg)
    {
        maxSum = status.maxNeg;
    }

    return maxSum;
}

int main()
{
    int n;
    std::cin >> n;

    /*
    формируем структуру, отражающую ситуацию при обработке чисел на текущий момент:
    - флаги наличия чисел = false;
    - максимальная сумма положительных чисел = 0;
    - максимальная сумма отрицательных чисел = INT_MIN.
    */
    SumsFlags status = {false, false, false, INT_MIN, 0};

    // определеняем максимальные суммы подпоследовательностей положительных и отрицательных чисел
    countSums(n, status);

    // выводим максимальное значение из вычисленных
    std::cout << findMaxSum(status) << std::endl;

    return 0;
}