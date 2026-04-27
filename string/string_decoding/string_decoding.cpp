#include <iostream>
#include <fstream>
#include <string>

/*
Сложность по времени: O(n), n - количество символов
Сложность по памяти: O(n)
*/

//функция декодирования
std::string decoding(const std::string &input)
{
    size_t inputSize = input.size();
    std::string result;    

    //так как символы `#` стоят после закодированного ими символа,
    //идём от конца к началу
    for (size_t i = inputSize; i-- > 0;)
    {
        char bufChar = input[i];
        char codedChar;
        if (bufChar == '#' && i >= 2)
        {
            std::string bufString;
            bufString.push_back(input[i - 2]);
            bufString.push_back(input[i - 1]);
            codedChar = static_cast<char>('a' + stoi(bufString) - 1);
            bufString.clear();
            i -= 2;
        }
        else
        {
            codedChar = static_cast<char>('a' + (bufChar - '0') - 1);
        }
        //вставляем в начало результата, так как исходную строку
        //обрабатываем от конца к началу
        result.insert(result.begin(), codedChar);
    }

    return result;
}

int main()
{

    std::string input;
    getline(std::cin, input);
    
    //выводим результат декодирования
    std::cout << decoding(input) << std::endl;

    return 0;
}
