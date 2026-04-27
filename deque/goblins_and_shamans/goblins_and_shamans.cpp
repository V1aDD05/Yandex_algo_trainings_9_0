#include <iostream>
#include <string>
#include <deque>

void checkOrder(const int n, std::istream &in)
{
    // во избежание дорогой операции insert, можно было сделать две deque: left и right
    std::deque<int> left;
    std::deque<int> right;

    std::string line;
    for (int i = 0; i < n; ++i)
    {
        getline(in, line);

        size_t lineSize = line.size();
        if (line[0] == '+')
        {
            right.push_back(stoi(line.substr(2, lineSize)));
            if (right.size() > left.size())
            {
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else if (line[0] == '*')
        {
            left.push_back(stoi(line.substr(2, lineSize)));
            if (left.size() > right.size() + 1)
            {
                right.push_front(left.back());
                left.pop_back();
            }
        }
        else if (line[0] == '-')
        {
            std::cout << left[0] << std::endl;
            left.pop_front();
            if (right.size() > left.size())
            {
                left.push_back(right.front());
                right.pop_front();
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();

    checkOrder(n, std::cin);

    return 0;
}