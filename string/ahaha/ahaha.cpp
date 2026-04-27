#include <iostream>
#include <string>
#include <algorithm>    //std::max

/*
Сложность по времени: O(N)
Сложность по памяти: O(N)
*/

int findMaxLength(int length, const std::string &girlStroke)
{
    //структура, хранящая данные о статусе обработки ответа
    struct LaughStatus
    {
        // индикатор нахождения внутри подстроки,
        // являющейся смехом
        bool isInside = false;
        // индикатор предыдущей буквы подстроки,
        // являющейся смехом
        bool isA = false;
        // индикатор наличия в подстроке, являющейся смехом, букв 'a'
        bool wasA = false;
        // индикатор наличия в подстроке, являющейся смехом, букв 'h'
        bool wasH = false;
        // индикатор следования двух букв `a` или `h` подряд
        bool duplication = false;

        // счётчик длины текущей подстроки, являющейся смехом
        int laughCounter = 0;

        // максимальная длина подстроки, являющейся смехом
        int maxLength = 0;
    };

    /*
    индикаторы "wasA", "wasH" и "duplication" приходится вводить, так как
    "a" - смех, "aa" - не смех, а "haa" - смех (подстрока "ha")

    проверка подобных случаев выполняетсяя в конце функции внутри блока `if (currentStatus.isInside){}`*/

    LaughStatus currentStatus;

    size_t strokeLength = girlStroke.size();
    for (size_t i = 0; i < strokeLength; ++i)
    {
        char bufChar = girlStroke[i];
        if (!currentStatus.isInside)
        {
            //случай начала смеха с 'a'
            if (bufChar == 'a')
            {
                currentStatus.isInside = true;
                currentStatus.laughCounter = 1;
                currentStatus.isA = true;
                currentStatus.wasA = true;
            }
            // случай начала смеха с 'h'
            else if (bufChar == 'h')
            {
                currentStatus.isInside = true;
                currentStatus.laughCounter = 1;
                currentStatus.isA = false;
                currentStatus.wasH = true;
            }

            continue;
        }
        else {
            if (currentStatus.isA)
            {
                //случай, когда в смехе "..ah"
                if (bufChar == 'h') {
                    ++currentStatus.laughCounter;
                    currentStatus.isA = false;
                    currentStatus.wasH = true;
                    currentStatus.duplication = false;
                }
                // случай, когда в смехе "..aa"
                else {
                    if (bufChar == 'a')
                    {
                        // случай, когда в смехе "..haa"
                        // иначе "aa" - не смех
                        if (currentStatus.wasH)
                        {
                            currentStatus.maxLength = std::max(currentStatus.laughCounter, currentStatus.maxLength);
                        }
                        currentStatus.duplication = true;

                        currentStatus.laughCounter = 1;
                        currentStatus.isA = true;
                        currentStatus.wasA = true;
                        currentStatus.wasH = false;
                    }
                    //случай, когда смех прерывается 
                    //другими символами
                    else {
                        currentStatus.isInside = false;
                        currentStatus.maxLength = std::max(currentStatus.laughCounter, currentStatus.maxLength);
                        currentStatus.laughCounter = 0;
                        currentStatus.wasA = false;
                        currentStatus.wasH = false;
                    }
                    
                }
            }
            else {
                // случай, когда в смехе "..ha"
                if (bufChar == 'a')
                {
                    ++currentStatus.laughCounter;
                    currentStatus.isA = true;
                    currentStatus.wasA = true;
                    currentStatus.wasH = true;
                    currentStatus.duplication = false;
                }
                else
                {
                    // случай, когда в смехе "..hh"
                    if (bufChar == 'h')
                    {
                        // случай, когда в смехе "..ahh"
                        // иначе "hh" - не смех
                        if (currentStatus.wasA)
                        {
                            currentStatus.maxLength = std::max(currentStatus.laughCounter, currentStatus.maxLength);
                        }
                        currentStatus.duplication = true;
                        currentStatus.laughCounter = 1;
                        currentStatus.isA = false;
                        currentStatus.wasA = false;
                    }
                    // случай, когда смех прерывается
                    // другими символами
                    else {
                        currentStatus.isInside = false;
                        currentStatus.maxLength = std::max(currentStatus.laughCounter, currentStatus.maxLength);
                        currentStatus.laughCounter = 0;
                        currentStatus.wasA = false;
                        currentStatus.wasH = false;
                    }
                    
                }
            }
        }
    }
    // выделение случаев типа "a" - смех, "aa" - не смех, а "haa" - смех (подстрока "ha")
    if (currentStatus.isInside)
    {

        if ((currentStatus.wasA && currentStatus.wasH) || (currentStatus.wasA && currentStatus.laughCounter == 1 && !currentStatus.duplication) || (currentStatus.wasH && currentStatus.laughCounter == 1 && !currentStatus.duplication))
        {
            currentStatus.maxLength = std::max(currentStatus.laughCounter, currentStatus.maxLength);
        }
    }

    return currentStatus.maxLength;
}

int main()
{
    //считываем длину ответа
    int length;
    std::cin >> length;
    std::cin.ignore();

    //считываем ответ
    std::string girlStroke;
    getline(std::cin, girlStroke);

    std::cout << findMaxLength(length, girlStroke) << std::endl;

    return 0;
}