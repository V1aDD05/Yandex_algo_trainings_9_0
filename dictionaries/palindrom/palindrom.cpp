#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>

/*
Сложность по времени: O(n), n - количество запросов
Сложность по памяти: O(m), m <= n - количество клиентов
*/

// функция формирования словаря
std::map<char, int> fillAlphabet(const int n)
{
    // map хранит ключи в "алфавитном" порядке, что для нас удобно
    std::map<char, int> letters;

    // заполняем словарь, где ключ - латинская буква,
    // значение - число появлений во вводе
    for (int i = 0; i < n; ++i)
    {
        char bufChar;
        std::cin >> bufChar;
        ++letters[bufChar];
    }

    return letters;
}

// функция формирования лексикографически минимального палиндрома
std::string minimalPalindrome(std::map<char, int> &letters)
{
    //нам нужен первый в алфавитном порядке
    //из самых длинных палиндромов:
    // AXSASXA вместо AXSBSXA

    std::queue<char> left;  //одну букву пары дозаписываем сюда в конец
    std::stack<char> right; //другую букву пары дозаписываем сюда в начало

    // средний символ будем хранить отдельно
    // по описанной выше причине
    char middleChar;
    bool isMiddle = false;

    //указатель на место результирующей строки, 
    //куда вставлять символы
    size_t midPointer = 0;

    for (const auto& letter : letters) {
        int charQuantity = letter.second;
        char bufChar = letter.first;

        if (charQuantity % 2 != 0)
        {
            //доводим количество до чётного значения
            --charQuantity;
            // если количество нечётное, то самую раннюю букву
            // из "нечётных" сохраняем для среднего символа
            if (!isMiddle)
            {
                isMiddle = true;
                middleChar = bufChar;
            }
        }
        while (charQuantity > 0) {
            //дозапиываем две буквы, а указатель среднего положения сдвигаем на 1
            left.push(bufChar);
            right.push(bufChar);

            charQuantity -= 2;
        }

    }
    
    //строка для формирования результирующего палиндрома
    std::string palindrome;

    //переписываем буквы из левой половины
    size_t halfSize = left.size();
    for (size_t i = 0; i < halfSize; ++i)
    {
        palindrome += left.front();
        left.pop();
    }

    // если в принципе есть средняя буква, дописываем её
    if (isMiddle)
    {
        palindrome += middleChar;
    }

    //переписываем буквы из правой половины
    for (size_t i = 0; i < halfSize; ++i)
    {
        palindrome += right.top();
        right.pop();
    }

    return palindrome;
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    // формируем словарь, где ключ - латинская буква
    // значение - число появлений во вводе
    std::map<char, int> letters = fillAlphabet(n);

    //формируем и выводим лексикографически минимальный палиндром
    std::cout << minimalPalindrome(letters) << std::endl;

    return 0;
}