#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> wrap(int vecSize, const vector<int> &inputVec)
{
    pair<int, int> result;

    // при 3 и более ненулевых элементах найдётся х.б. + произведение
    // создавать кортеж для - произведения смысла нет
    tuple<long long, int, int> maxPos(0, 0, 0);
    tuple<long long, int, int> maxNeg(0, 0, 0);

    int posCounter = 0;
    int negCounter = 0;

    // все случаи с нулём по условию должны попасть сюда
    if (vecSize == 2)
    {
        result.first = min(inputVec[0], inputVec[1]);
        result.second = max(inputVec[0], inputVec[1]);
        return result;
    }
    // при 3 и более ненулевых элементах найдётся х.б. + произведение
    else
    {
        for (auto member : inputVec)
        {
            if (member > 0)
            {
                ++posCounter;
                if (posCounter == 1)
                {
                    get<1>(maxPos) = member;
                }
                if (posCounter == 2)
                {
                    if (get<1>(maxPos) < member)
                    {
                        get<2>(maxPos) = get<1>(maxPos);
                        get<1>(maxPos) = member;
                    }
                    else
                    {
                        get<2>(maxPos) = member;
                    }
                }
                if (posCounter > 2)
                {
                    if (get<1>(maxPos) < member)
                    {
                        get<2>(maxPos) = get<1>(maxPos);
                        get<1>(maxPos) = member;
                    }
                    else if (get<2>(maxPos) < member)
                    {
                        get<2>(maxPos) = member;
                    }
                }
            }
            if (member < 0)
            {
                ++negCounter;
                if (negCounter == 1)
                {
                    get<1>(maxNeg) = member;
                }
                if (negCounter == 2)
                {
                    if (get<1>(maxNeg) < member)
                    {
                        get<2>(maxNeg) = get<1>(maxNeg);
                        get<1>(maxNeg) = member;
                    }
                    else
                    {
                        get<2>(maxNeg) = member;
                    }
                }
                if (negCounter > 2)
                {
                    if (get<2>(maxNeg) > member)
                    {
                        get<1>(maxNeg) = get<2>(maxNeg);
                        get<2>(maxNeg) = member;
                    }
                    else if (get<1>(maxNeg) > member)
                    {
                        get<1>(maxNeg) = member;
                    }
                }
            }
        }
        if (posCounter >= 2 && negCounter >= 2)
        {
            // явный static_cast во избежание переполнения
            get<0>(maxPos) = static_cast<long long>(get<1>(maxPos)) * get<2>(maxPos);
            get<0>(maxNeg) = static_cast<long long>(get<1>(maxNeg)) * get<2>(maxNeg);
            if (get<0>(maxPos) > get<0>(maxNeg))
            {
                result.first = get<2>(maxPos);
                result.second = get<1>(maxPos);
            }
            else
            {
                result.first = get<2>(maxNeg);
                result.second = get<1>(maxNeg);
            }
        }
        else if (posCounter >= 2 && negCounter < 2)
        {
            result.first = get<2>(maxPos);
            result.second = get<1>(maxPos);
        }
        else if (posCounter < 2 && negCounter >= 2)
        {
            result.first = get<2>(maxNeg);
            result.second = get<1>(maxNeg);
        }
    }

    return result;
}

int main()
{
    ifstream inputFile("input.txt");

    vector<int> inputVec;

    int buf;
    while (inputFile >> buf)
    {
        inputVec.push_back(buf);
    }

    int vecSize = inputVec.size();

    pair<int, int> outputPair = wrap(vecSize, inputVec);

    cout << outputPair.first << " " << outputPair.second << endl;

    return 0;
}
