#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    //std::max

/*
Сложность по времени: O(M), M - количество нажатых клавиш
Сложность по памяти: O(K + (M - K)*K) = O(M*K), где
M - количество нажатых клавиш, K - количество отображаемых в окне символов.
*/

struct InitParams
{
    int windows;        // количество окон на компьютере
    int clicks;         // количество нажатий клавиш
    int windowBuffer;   // ограничение на количество отображаемых в окне символов
};

std::vector<std::string> simulation(int &queuePtr, const InitParams& params)
{
    //вектор, хранящий символы каждого из окон
    std::vector<std::string> queueVec(params.windows);

    //строка, имитирующая буфер обмена
    std::string buffer;

    for (int i = 0; i < params.clicks; ++i)
    {
        std::string line;
        getline(std::cin, line);

        if (line == "Next")
        {
            ++queuePtr;
            queuePtr = queuePtr % params.windows;
        }
        else if (line == "Copy")
        {
            buffer.clear();

            int bufQueueSize = static_cast<int>(queueVec[queuePtr].size());
            // если в окне символов больше, чем params.windowBuffer, 
            // копировать символы начнём не с начала вектора
            int maxStart = std::max(0, bufQueueSize - params.windowBuffer);

            // копируем не более params.windowBuffer символов, начиная с maxStart
            buffer.append(queueVec[queuePtr], maxStart, bufQueueSize - maxStart);
        }
        else if (line == "Paste")
        {
            size_t bufferSize = buffer.size();
            queueVec[queuePtr].append(buffer);
        }
        else if (line == "Backspace")
        {
            if (!queueVec[queuePtr].empty())
            {
                queueVec[queuePtr].pop_back();
            }
        }
        else
        {
            char bufChar = line[0];
            queueVec[queuePtr].push_back(bufChar);
        }
    }
    return queueVec;
}

int main()
{
    // считываем количество окон на компьютере, количество нажатий клавиш
    // и ограничение на количество отображаемых в окне символов
    int n, m, k;
    std::cin >> n >> m >> k;
    std::cin.ignore();

    InitParams params = {n, m, k};

    // номер открытого окна
    int queuePtr = 0;

    //формируем результат, проводя симуляцию процесса ввода данных
    std::vector<std::string> queueVec = simulation(queuePtr, params);

    //выводим информацию, которая будет отображена на "экране" в результате симуляции
    if (!queueVec[queuePtr].empty())
    {
        std::cout << queueVec[queuePtr].substr(std::max(0, static_cast<int>(queueVec[queuePtr].size()) - k)) << std::endl;
    }
    else
    {
        std::cout << "Empty" << std::endl;
    }

    return 0;
}