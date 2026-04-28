#include <iostream>
#include <string>
#include <stack>

/*
Сложность по времени: O(max(n, l)), l - размер "алфавита"
(строки, характеризующей лексикографический порядок скобок)
Сложность по памяти: O(max(n, l))
*/

// функция заполняющая стек скобок в начальный момент времени
std::stack<char> fillStack(const std::string &s)
{
    std::stack<char> charStack;
    for (const auto &bufChar : s)
    {
        if (bufChar == '(')
        {
            charStack.push('(');
        }
        else if (bufChar == '[')
        {
            charStack.push('[');
        }
        //если получаем закрывающие скобки, удаляем лежащие в стеке
        //соответствующие им открывающие
        else if (bufChar == ')')
        {
            if (charStack.top() == '(')
            {
                charStack.pop();
            }
        }
        else if (bufChar == ']')
        {
            if (charStack.top() == '[')
            {
                charStack.pop();
            }
        }
    }

    return charStack;
}

//функция формирования наименьшей искомой строки
std::string complementCPS(std::string &s, const std::string& alphabet, const int n)
{
    std::stack<char> charStack = fillStack(s);

    size_t pointer = s.size();

    size_t alpSize = alphabet.size();

    // дозаполняем строку исходного размера 'pointer' до размера 'n'
    while (pointer < n)
    {
        //перебираем скобки в заданном лексикографическом порядке
        //для выбора наилучшей подстановки
        for (const auto &alphChar : alphabet)
        {
            if (alphChar == '(' && (n - pointer > charStack.size()))
            {
                charStack.push(alphChar);
                s.push_back(alphChar);
                break;
            }
            else if (alphChar == '[' && (n - pointer > charStack.size()))
            {
                charStack.push(alphChar);
                s.push_back(alphChar);
                break;
            }
            else if (alphChar == ')' && !charStack.empty() && charStack.top() == '(')
            {
                charStack.pop();
                s.push_back(alphChar);
                break;
            }
            else if (alphChar == ']' && !charStack.empty() && charStack.top() == '[')
            {
                charStack.pop();
                s.push_back(alphChar);
                break;
            }
        }
        ++pointer;
    }
    return s;
}


int main()
{
    //считываем длину искомой строки
    int n;
    std::cin >> n;
    std::cin.ignore();

    // считываем строку, характеризующую лексикографический порядок скобок
    std::string alphabet;
    std::cin >> alphabet;

    //считываем начало искомой строки
    std::string s;
    std::cin >> s;

    //формируем искомую строку
    std::cout << complementCPS(s, alphabet, n) << std::endl;

    return 0;
}