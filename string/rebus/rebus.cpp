#include <iostream>
#include <string>
#include <vector>

/*
Сложность по времени: O(n), n - количество символов
Сложность по памяти: O(n)
*/

// функция формирования вектора "слов" (с апострофами)
std::vector<std::string> createStringVector()
{
    // вектор "слов" (с апострофами)
    std::vector<std::string> strVec;

    // буфер для формирования "слова"
    std::string bufStr;

    // проходим всю входную строку и разбиваем на "слова" (с апострофами)
    char inputChar;
    while (std::cin.get(inputChar) && inputChar != '\n')
    {
        //формируем "слово", пока не встретим пробел
        if (inputChar != ' ')
        {
            bufStr.push_back(inputChar);
        }
        else
        {
            strVec.push_back(bufStr);
            bufStr.clear();
        }
    }
    strVec.push_back(bufStr);

    return strVec;
}

// функция "обрезки" "слова"
std::string trimApostrophes(std::string &part)
{
    struct CharsPosition
    {   
        // счётчик апострофов в начале слова
        int beginCounter;

        // счётчик апострофов в конце слова
        int endCounter;

        // длина слова после "обрезки"
        int len;

        //размер слова до "обрезки" с учётом апострофов
        int partSize;

        CharsPosition(size_t ptSz) : beginCounter(0),
                                     endCounter(0),
                                     partSize(ptSz) {};
    };

    CharsPosition positions(static_cast<int>(part.size()));

    int aposNum = 39; // код апострофа 39

    // считаем количество апострофов в начале "слова"
    if (part[0] == aposNum)
    {
        int i = 0;
        while (part[i] == aposNum)
        {
            ++positions.beginCounter;
            ++i;
        }
    }

    // считаем количество апострофов в конце "слова"
    if (part[positions.partSize - 1] == aposNum)
    {
        int j = positions.partSize - 1;
        while (part[j] == aposNum)
        {
            ++positions.endCounter;
            --j;
        }
    }

    // гарантируется, что ребус корректен -> не проверяем, что
    // len >= 0
    int len = positions.partSize - 2 * (positions.endCounter + positions.beginCounter);

    // первые positions.beginCounter символов - апострофы,
    // следующие за ними positions.beginCounter символов не учитываем.
    // не прибавляем 1, так как индексация строк начинается с нуля
    return part.substr(2 * positions.beginCounter, len);
}

//функция формирования результата - решённого ребуса
std::string createResult(const std::vector<std::string> &strVec)
{
    size_t vecSize = strVec.size();
    std::string result;
    std::string part;
    std::string buf;
    for (size_t i = 0; i < vecSize; ++i)
    {
        //каждое из выделенных "слов" отправляем в функцию, 
        //убирающую "лишние" символы 
        part = strVec[i];
        buf = trimApostrophes(part);

        //остаток слова добавляем к результату
        result += buf;
    }

    return result;
}

int main()
{
    // вектор "слов" (с апострофами)
    std::vector<std::string> strVec = createStringVector();

    //формируем и выводим результат решения ребуса
    std::cout << createResult(strVec) << std::endl;

    return 0;
}