#include <iostream>
#include <string>
#include <map>
#include <algorithm>    //std::min

/*
Сложность по времени: O(n*logn + n*L) = O(n*max(logn, L)), L-длина слов
Сложность по памяти: O(N)
*/

int findMinIntersect(std::map<std::string, int> &stringMap)
{

    struct IntersectionSearch{
        //индикатор того, что записали первую строчку из пары 
        bool isFirstFound;

        //размер строки
        const int wordSize;

        //величина минимального выявленного пересечения между строками
        int minIntersect;

        //переменные, в которые будем записывать строки 
        //при составлении пары и сравнении значений пары
        std::string firstStr, secondStr;

        // конструктор по умолчанию (для того, 
        //чтобы получить wordSize из stringMap, передаваемой в функцию извне)
        IntersectionSearch(int ws) : isFirstFound(false),
                                     wordSize(ws),
                                     minIntersect(wordSize),
                                     firstStr(),
                                     secondStr() {};
    };
    // по условию, последовательность строк не пустая,
    // поэтому не проверяем на stringMap.empty()
    int ws = static_cast<int>(stringMap.begin()->first.size());
    IntersectionSearch status(ws);


    // проходы по map. В худшем случае сложность O(n*L), L-длина слов
    // итерация по элементам для map - красно-чёрного дерева - имеет
    // амортизированную сложность O(n), а не O(nLogn)

    // применяем map, поэтому строки отсортированы, поэтому лучше сравнивать
    // ближайшие друг к другу с учётом неётности (см. ниже)

    for (auto &stringUnit : stringMap)
    {
        // если количество повторений чётное, такие строки рассматривать не нужно:
        // тогда эти строки будут попарно совпадать по всем символам
        if (stringUnit.second % 2 != 0)
        {
            // если записываем первую строку из пары
            if (!status.isFirstFound)
            {
                status.firstStr = stringUnit.first;
                status.isFirstFound = true;
            }
            else
            {
                status.secondStr = stringUnit.first;
                status.isFirstFound = false;

                //посимвольно сравниваем две строки
                //до первого различающегося символа

                // счётчик числа совпадающих символов в начале строк
                int commonPrefixLength = 0; 
                while (commonPrefixLength < status.wordSize && status.firstStr[commonPrefixLength] == status.secondStr[commonPrefixLength])
                {
                    ++commonPrefixLength;
                }
                status.minIntersect = std::min(commonPrefixLength, status.minIntersect);
            }
        }
    }

    //если в крайней итерации записали содержимое в строку first,
    //а для строки second уже ничего не осталось, то разбить на пары
    //не представляется возможным -> совпадающих букв 0.
    if (status.isFirstFound)
    {
        status.minIntersect = 0;
    }

    return status.minIntersect;
}

int main()
{
    int quantity;
    std::cin >> quantity;
    std::cin.ignore();

    // применяем map - получаем "алфавитный" порядок строк,
    // обеспечивающий наилучшее совпадение соседних строк
    // ключ - строка, значение - количество появлений во входных данных
    std::map<std::string, int> stringSet;

    // Заполнение - в худшем случае O(nlogn)
    for (int i = 0; i < quantity; ++i)
    {
        std::string bufStr;
        std::cin >> bufStr;
        ++stringSet[bufStr];
    }

    //Определяем максимальное значение 'k' - количества первых букв,
    //попарно совпадающих у строк набора
    std::cout << findMinIntersect(stringSet) << std::endl;

    return 0;
}