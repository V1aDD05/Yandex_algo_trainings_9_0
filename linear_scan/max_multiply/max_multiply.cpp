#include <iostream>
#include <vector>
#include <utility>      //std::pair
#include <algorithm>    //std::max, std::min

/*
Сложность по времени: O(n).
Сложность по памяти: O(n)
*/

//структура, хранящая информацию о найденных множителях
struct Candidates {
    std::pair<int, int> maxPos = {0,0};     //два наибольших "+" числа
    std::pair<int, int> maxNeg = {0, 0};    // два наибольших "-" числа
    int posCounter = 0;                     // счётчик "+" чисел
    int negCounter = 0;                     // счётчик "-" чисел
};

Candidates detectPairs(const std::vector<int> &inputVec)
{
    Candidates candidate;

    // при 3 и более ненулевых элементах найдётся х.б. одно + произведение
    for (auto member : inputVec)
    {
        if (member > 0)
        {
            //в зависимости от количества кандидатов на максимальный
            //множитель, по-разному располагаем найденный множитель
            ++candidate.posCounter;
            if (candidate.posCounter == 1)
            {
                candidate.maxPos.first = member;
            }
            if (candidate.posCounter == 2)
            {
                if (candidate.maxPos.first < member)
                {
                    candidate.maxPos.second = candidate.maxPos.first;
                    candidate.maxPos.first = member;
                }
                else
                {
                    candidate.maxPos.second = member;
                }
            }
            if (candidate.posCounter > 2)
            {
                if (candidate.maxPos.first < member)
                {
                    candidate.maxPos.second = candidate.maxPos.first;
                    candidate.maxPos.first = member;
                }
                else if (candidate.maxPos.second < member)
                {
                    candidate.maxPos.second = member;
                }
            }
        }
        if (member < 0)
        {

            // в зависимости от количества кандидатов на максимальный
            // множитель, по-разному располагаем найденный множитель
            ++candidate.negCounter;
            if (candidate.negCounter == 1)
            {
                candidate.maxNeg.first = member;
            }
            if (candidate.negCounter == 2)
            {
                if (candidate.maxNeg.first < member)
                {
                    candidate.maxNeg.second = candidate.maxNeg.first;
                    candidate.maxNeg.first = member;
                }
                else
                {
                    candidate.maxNeg.second = member;
                }
            }
            if (candidate.negCounter > 2)
            {
                if (candidate.maxNeg.second > member)
                {
                    candidate.maxNeg.first = candidate.maxNeg.second;
                    candidate.maxNeg.second = member;
                }
                else if (candidate.maxNeg.first > member)
                {
                    candidate.maxNeg.first = member;
                }
            }
        }
    }

    return candidate;
}

//функция выбора пары множителей, дающих максимальное произведение,
//из найденных кандидатов 
std::pair<int, int> choosePair(const Candidates& candidate)
{
    std::pair<int, int> result;

    long long int posMul;
    long long int negMul;

    // если присутствует и пара "-" чисел, и пара "+",
    // выбираем ту, которая даст большее произведение
    if (candidate.posCounter >= 2 && candidate.negCounter >= 2)
    {
        // явный static_cast во избежание переполнения
        posMul = static_cast<long long>(candidate.maxPos.first) * candidate.maxPos.second;
        negMul = static_cast<long long>(candidate.maxNeg.first) * candidate.maxNeg.second;
        if (posMul > negMul)
        {
            result.first = candidate.maxPos.second;
            result.second = candidate.maxPos.first;
        }
        else
        {
            result.first = candidate.maxNeg.second;
            result.second = candidate.maxNeg.first;
        }
    }
    else if (candidate.posCounter >= 2 && candidate.negCounter < 2)
    {
        result.first = candidate.maxPos.second;
        result.second = candidate.maxPos.first;
    }
    else if (candidate.posCounter < 2 && candidate.negCounter >= 2)
    {
        result.first = candidate.maxNeg.second;
        result.second = candidate.maxNeg.first;
    }

    return result;
}

// функция определения пары множителей, дающих максимальное произведение
std::pair<int, int> findMaxPair(const std::vector<int> &inputVec)
{
    size_t vecSize = inputVec.size();
    std::pair<int, int> result;

    // все случаи с нулём по условию должны попасть сюда
    if (vecSize == 2)
    {
        result.first = std::min(inputVec[0], inputVec[1]);
        result.second = std::max(inputVec[0], inputVec[1]);
        return result;
    }    

    // формируем пару наибольших по модулю "+" и "-" элементов
    Candidates candidateVar = detectPairs(inputVec);

    //выбираем пару, дающую наибольшее произведение
    result = choosePair(candidateVar);

    return result;
}

int main()
{
    //вектор чисел
    std::vector<int> inputVec;

    int buf;
    while (std::cin >> buf)
    {
        inputVec.push_back(buf);
    }

    //определяем пару множителей, дающих максимальное произведение
    std::pair<int, int> outputPair = findMaxPair(inputVec);

    std::cout << outputPair.first << " " << outputPair.second << std::endl;

    return 0;
}
