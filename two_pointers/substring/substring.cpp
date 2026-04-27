#include <iostream>
#include <string>
#include <unordered_map>

/*
Сложность по времени: O(n), n - суммарное количество чисел в двух наборах
Сложность по памяти: O(p), p -количество символов в алфавите
*/


// функция поиска максимальной удовлетворяющей условию подстроки
std::pair<int, int> findMaxSubstr(const int k, const std::string &stroke)
{
    //пара выводмых значений: длины и позиции первого символа подстроки
    std::pair<int,int> result = {0,0};
    std::unordered_map<char, int> alphabet;

    int left = 0;
    int right = 0;

    const int n = static_cast<int>(stroke.size());

    while (right < n)
    {
        //двигаем правую границу подстроки вправо, 
        //пока повторений правого символа не станет больше k,
        //либо исходная строка не закончится
        ++alphabet[stroke[right]];
        if (alphabet[stroke[right]] > k)
        {
            //запоминаем длину подстроки
            int bufLen = right - left;
            if (bufLen > result.first)
            {
                result.first = bufLen;
                result.second = left;
            }
            // двигаем левую границу вправо, пока 
            //повторений правого символа больше k
            while (alphabet[stroke[right]] > k)
            {
                --alphabet[stroke[left]];
                ++left;
            }
        }
        ++right;
    }

    //рассматриваем случай, когда правый символ подстроки является
    //правым символом исходной строки и потому не произошло рассмотрения в цикле
    int bufLen = right - left;
    if (bufLen > result.first)
    {
        result.first = bufLen;
        result.second = left;
    }

    if (!result.first)
    {
        result.first = 0;
        result.second = 0;
    }

    return result;
}


int main()
{
    //считываем количество символов в строке и
    //максимальное количество повторов символа в формируемой подстроке
    int n, k;
    std::cin >> n >> k;

    //считываем непосредственно строку
    std::string stroke;
    std::cin >> stroke;

    // пара выводмых значений: длины и позиции первого символа подстроки
    std::pair<int, int> result = findMaxSubstr(k, stroke);

    std::cout << result.first << " " << result.second + 1 << std::endl;

    return 0;
}