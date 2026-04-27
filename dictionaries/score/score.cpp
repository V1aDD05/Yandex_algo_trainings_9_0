#include <iostream>
#include <sstream> //std::istringstream
#include <string>
#include <unordered_map>

void enterPlayers(std::unordered_map<std::string, int> &gameNotes, const int playersQuantity, std::istream &in)
{
    std::string bufString;
    for (int i = 0; i < playersQuantity; ++i)
    {
        in >> bufString;
        gameNotes[bufString] = 0;
    }
}

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
    // заносим в словарь игроков
    int playersQuantity;
    std::cin >> playersQuantity;
    std::cin.ignore();
    std::unordered_map<std::string, int> gameNotes;

    enterPlayers(gameNotes, playersQuantity, std::cin);

    // заносим в словарь стенограмму игры
    int notesQouantity;
    std::cin >> notesQouantity;
    std::cin.ignore();

    enterScore(gameNotes, notesQouantity, std::cin);

    //выводим результат игрока, забившего больше всех
    std::cout << getMaxName(gameNotes) << std::endl;

    return 0;
}