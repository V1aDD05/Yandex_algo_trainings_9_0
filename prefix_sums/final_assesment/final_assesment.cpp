#include <iostream>

/*
Сложность по времени: O(N)
Сложность по памяти: O(1).
*/

//структура, хранящая данные о семестровых оценках студента
struct ScoreInfo
{
    int prefSum;      // префиксная сумма оценок
    int scoreCounter; // счётчик оценок
    char minChar;     // переменная, хранящая худшую оценку
};

//функция определения средней оценки
char getMidScore(const ScoreInfo &scores)
{
    // по условию строка непустая, проверку на scoreCounter == 0 не выполняем

    // средняя оценка
    double middle = static_cast<double>(scores.prefSum) / scores.scoreCounter;

    // дробная часть средней оценки
    double diff = middle - scores.prefSum / scores.scoreCounter;

    // округление в зависимости от значения дробной части средней оценки
    int round;
    if ((diff - 0.5) < 1e-6)
    {
        round = scores.prefSum / scores.scoreCounter;
    }
    else
    {
        round = (scores.prefSum / scores.scoreCounter) + 1;
    }

    return static_cast<char>('A' + round);
}

//функция определения итоговой оценки
char getResult(const int midChar, const int minChar)
{
    char result;
    if (midChar + 1 < minChar)
    {
        result = static_cast<char>(minChar - 1);
    }
    else
    {
        result = midChar;
    }

    return result;
}

int main()
{
    ScoreInfo scores = {0, 0, 'A'};
    char bufChar;

    // подсчёт префиксной суммы, количества оценок,
    // определение худшей оценки
    while (std::cin.get(bufChar) && bufChar != '\n')
    {
        ++scores.scoreCounter;
        scores.prefSum += (bufChar - 'A');
        if (bufChar > scores.minChar) // а надо ли вычитать?
        {
            scores.minChar = bufChar;
        }
    }

    //определяем среднюю оценку
    char midChar = getMidScore(scores);
    //определяем итоговую оценку
    std::cout << getResult(midChar, scores.minChar) << std::endl;

    return 0;
}