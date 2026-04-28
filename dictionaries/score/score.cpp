#include <iostream>
#include <sstream> //std::istringstream
#include <string>
#include <unordered_map>

/*
Сложность по времени: O(n + m), где
n - количество игроков, m - количество запросов
Сложность по памяти: O(n).
*/

//функция заполнения ключей словаря (фамилий игроков)
void enterPlayers(std::unordered_map<std::string, int> &gameNotes, const int playersQuantity, std::istream &in)
{
    std::string bufString;
    for (int i = 0; i < playersQuantity; ++i)
    {
        in >> bufString;
        gameNotes[bufString] = 0;
    }
}

//функция заполнения значений словаря по стенограмме игры 
void enterScore(std::unordered_map<std::string, int> &gameNotes, const int notesQouantity, std::istream &in)
{
    int leftPrev, leftCurr, rightPrev, rightCurr;
    
    leftPrev = 0;
    rightPrev = 0;

    for (int i = 0; i < notesQouantity; ++i)
    {
        //считываем строку стенограммы
        std::string bufString;
        std::getline(in, bufString);
        std::istringstream iss(bufString);

        //разбиваем строку на счёт в левом и правом кольцах и имя
        std::string leftStr, rightStr, name;
        std::getline(iss, leftStr, ':');
        std::getline(iss, rightStr, ' ');
        std::getline(iss, name);

        leftCurr = std::stoi(leftStr);
        rightCurr = std::stoi(rightStr);

        //записываем очки забросившему игроку
        if (leftCurr > leftPrev)
        {
            gameNotes[name] += (leftCurr - leftPrev);
            leftPrev = leftCurr;
        }
        else if (rightCurr > rightPrev)
        {
            gameNotes[name] += (rightCurr - rightPrev);
            rightPrev = rightCurr;
        }
    }
}

//функция поиска самого результативного игрока
std::string getMaxName(std::unordered_map<std::string, int> &gameNotes)
{
    int maxSum = 0;
    std::string maxName;

    for (const auto &player : gameNotes)
    {
        if (player.second > maxSum)
        {
            maxSum = player.second;
            maxName = player.first;
        }
    }

    std::string result = maxName + ' ' + std::to_string(maxSum);
    return result;
}


int main()
{
    //считываем количество игроков
    int playersQuantity;
    std::cin >> playersQuantity;
    std::cin.ignore();

    //словарь игроков: ключ - фамилия, значение - счёт
    std::unordered_map<std::string, int> gameNotes;

    // заносим в словарь игроков
    enterPlayers(gameNotes, playersQuantity, std::cin);

    //считываем количество записей
    int notesQouantity;
    std::cin >> notesQouantity;
    std::cin.ignore();

    // заносим в словарь стенограмму игры
    enterScore(gameNotes, notesQouantity, std::cin);

    //выводим результат игрока, забившего больше всех
    std::cout << getMaxName(gameNotes) << std::endl;

    return 0;
}