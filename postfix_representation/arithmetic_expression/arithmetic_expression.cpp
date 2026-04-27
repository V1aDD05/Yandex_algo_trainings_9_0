#include <iostream>
#include <sstream>
#include <string>
#include <stack>

/*
Сложность по времени: O(n).
Сложность по памяти: O(n)
*/

//***
//ПРОТОТИПЫ ФУНКЦИЙ
//***

// функция переноса верхней скобки/операции в стеке в постфиксную запись
void popPostfixStack(std::string &postfixStr, std::stack<char> &postfixStack);

// функция работы со стеком скобок и операций при добавлении новой скобки / операции
bool postfixStackProcessing(std::string &postfixStr, std::stack<char> &postfixStack, const char newChar);

// функция переноса выделенного числа в постфиксную запись
void intEnd(std::string &postfixStr, std::string &intStr, bool &isInsideInt);

// функция вычисления для постфиксной записи
void postfixComputation(std::string &postfixStr);

// функция формирования постфиксной записи выражения
std::string generatePostfixStr();

//***
//РЕАЛИЗАЦИИ ФУНКЦИЙ
//***

// функция переноса выделенного числа в постфиксную запись
void intEnd(std::string &postfixStr, std::string &intStr, bool &isInsideInt)
{
    postfixStr += intStr;
    postfixStr += ' ';
    intStr.clear();
    isInsideInt = false;
}

// функция переноса верхней скобки/операции в стеке в постфиксную запись
void popPostfixStack(std::string &postfixStr, std::stack<char> &postfixStack)
{
    if (!postfixStack.empty())
    {
        postfixStr += postfixStack.top();
        postfixStr += ' ';
        postfixStack.pop();
    }  
}

//функция работы со стеком скобок и операций
//при добавлении новой скобки / операции
bool postfixStackProcessing(std::string &postfixStr, std::stack<char> &postfixStack, const char newChar)
{
    bool isPossible = true;
    if (newChar == '-' || newChar == '+')
    {
        while (!postfixStack.empty() && (postfixStack.top() == '+' || postfixStack.top() == '-' || postfixStack.top() == '*'))
        {
            popPostfixStack(postfixStr, postfixStack);
        }
        postfixStack.push(newChar);
    }
    else if (newChar == '*')
    {
        while (!postfixStack.empty() && (postfixStack.top() == '*'))
        {
            popPostfixStack(postfixStr, postfixStack);
        }
        postfixStack.push(newChar);
    }
    else if (newChar == '(')
    {
        postfixStack.push(newChar);
    }
    else if (newChar == ')')
    {
        isPossible = false;
        while (!postfixStack.empty() && postfixStack.top() != '(')
        {
            popPostfixStack(postfixStr, postfixStack);
        }
        if (!postfixStack.empty() && postfixStack.top() == '(')
        {
            isPossible = true;
            postfixStack.pop();
        }
    }
    return isPossible;
}

// функция формирования постфиксной записи выражения
std::string generatePostfixStr()
{

    // строка, в которой будет храниться выражение в постфиксной записи
    std::string postfixStr = "";

    // флаг отсутствия ошибок
    bool isPossible = true;

    // стек, применяемый для формирования постфиксной записи
    std::stack<char> postfixStack;

    // строка для накопления цифр числа
    std::string intStr = "";
    // флаг процесса накопления цифр числа
    bool isInsideInt = false;

    // индикатор типа предыдущего символа
    //  o - operation, i - integer,b - opening bracket, c - closing bracket
    char previous = ' ';

    // флаг состояний, после которых возможен унарный минус
    bool unarySuspect = true;

    char bufChar;
    while (std::cin.get(bufChar) && bufChar != '\n')
    {
        if (bufChar == ' ')
        {
            if (isInsideInt)
            {
                intEnd(postfixStr, intStr, isInsideInt);
            }
            unarySuspect = false;
        }
        else if (isdigit(static_cast<unsigned char>(bufChar)))
        {
            if (isInsideInt)
            {
                intStr.push_back(bufChar);
            }
            else
            {
                if (previous == 'o' || previous == 'b' || previous == ' ')
                {
                    isInsideInt = true;
                    unarySuspect = false;
                    previous = 'i';
                    intStr.push_back(bufChar);
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }
        }
        else if (bufChar == '-')
        {
            if (unarySuspect)
            {
                unarySuspect = false;
                previous = 'o';
                postfixStr += "0 ";
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
            }
            else
            {
                if (previous == 'i' || previous == 'c')
                {
                    if (isInsideInt)
                    {
                        intEnd(postfixStr, intStr, isInsideInt);
                    }
                    previous = 'o';
                    isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
                }
                else
                {
                    isPossible = false;
                    break;
                }
            }
        }
        else if (bufChar == '+' || bufChar == '*')
        {
            if (previous == 'i' || previous == 'c')
            {
                if (isInsideInt)
                {
                    intEnd(postfixStr, intStr, isInsideInt);
                }
                previous = 'o';
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
            }
            else
            {
                isPossible = false;
                break;
            }
        }
        else if (bufChar == '(')
        {
            if (previous == 'o' || previous == ' ' || previous == 'b')
            {
                previous = 'b';
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
            }
            else
            {
                isPossible = false;
                break;
            }
            unarySuspect = true;
        }
        else if (bufChar == ')')
        {
            unarySuspect = false;
            if (previous == 'i' || previous == 'c')
            {
                if (isInsideInt)
                {
                    intEnd(postfixStr, intStr, isInsideInt);
                }
                previous = 'c';
                isPossible = postfixStackProcessing(postfixStr, postfixStack, bufChar);
                if (!isPossible)
                {
                    break;
                }
            }
            else
            {
                isPossible = false;
                break;
            }
        }
        else
        {
            isPossible = false;
            break;
        }
    }

    if (!intStr.empty())
    {
        postfixStr += intStr;
        postfixStr += ' ';
    }

    // осталось вытолкнуть из стека оставшиеся там операции
    while (!postfixStack.empty())
    {
        if (postfixStack.top() == '+' || postfixStack.top() == '-' || postfixStack.top() == '*')
        {
            popPostfixStack(postfixStr, postfixStack);
        }
        // случай, если там остались открывающие скобки
        else
        {
            isPossible = false;
            break;
        }
    }

    if (!isPossible)
    {
        postfixStr.clear();
    }

    return postfixStr;
}

// функция вычисления для постфиксной записи
void postfixComputation(std::string &postfixStr)
{
    // стек операндов
    std::stack<int> operands;
    // переменные, хранящие текущие операнды
    int left, right;

    // строка для накопления цифр числа
    std::string intStr;
    // флаг процесса накопления цифр числа
    bool isInsideInt = false;

    // флаг отсутствия ошибок
    bool isCorrect = true;

    std::istringstream iss(postfixStr);

    char bufChar;
    while (iss.get(bufChar) && bufChar != '\n')
    {
        if (isInsideInt)
        {
            if (bufChar == ' ')
            {
                isInsideInt = false;
                operands.push(stoi(intStr));
                intStr.clear();
            }
            else
            {
                intStr.push_back(bufChar);
            }
        }
        else if (bufChar != ' ')
        {
            if (bufChar == '+' || bufChar == '-' || bufChar == '*')
            {
                if (!operands.empty())
                {
                    right = operands.top();
                    operands.pop();
                }
                else
                {
                    isCorrect = false;
                    break;
                }

                if (!operands.empty())
                {
                    left = operands.top();
                    operands.pop();
                }
                else
                {
                    isCorrect = false;
                    break;
                }

                if (bufChar == '+')
                {
                    operands.push(left + right);
                }
                else if (bufChar == '-')
                {
                    operands.push(left - right);
                }
                else if (bufChar == '*')
                {
                    operands.push(left * right);
                }
            }
            else
            {
                intStr.push_back(bufChar);
                isInsideInt = true;
            }
        }
    }

    if (!isCorrect)
    {
        std::cout << "WRONG" << std::endl;
    }
    else
    {
        if (!intStr.empty())
        {
            operands.push(stoi(intStr));
        }
        if (intStr.size() <= 1)
        {
            std::cout << operands.top() << std::endl;
        }
        else
        {
            std::cout << "WRONG" << std::endl;
        }
    }
}



int main()
{   
    //строка, в которой будет храниться выражение в постфиксной записи
    std::string postfixStr = generatePostfixStr();

    //если удалось сформировать постфиксную запись без ошибок,
    //вычисляем выражение
    if (!postfixStr.empty())
    {
        postfixStr.pop_back();
        postfixComputation(postfixStr);
    }
    else
    {
        std::cout << "WRONG" << std::endl;
    }

    return 0;
}