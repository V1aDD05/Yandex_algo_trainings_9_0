#include <iostream>     //cin, cout
#include <vector>       //vector
#include <utility>      //pair
#include <algorithm>    //max,min

int findIntersection(const std::vector<std::pair<int, int>>& signals, const int n)
{
    std::pair<int, int> intersection = signals[0];

    std::pair<int, int> bufPair;

    for (int i = 1; i < n; ++i) {
        bufPair = signals[i];
        int moreLeft = std::max(intersection.first, bufPair.first);
        int lessRight = std::min(intersection.second, bufPair.second);

        if (moreLeft > lessRight) {
            intersection.second = -1;
            break;
        }
        else if (moreLeft == lessRight) {
            intersection.first = moreLeft;
            intersection.second = moreLeft;
        }
        else if (moreLeft < lessRight) {
            intersection.first = moreLeft;
            intersection.second = lessRight;
        }
    }

    return intersection.second;
}

int main()
{
    int n;

    std::cin >> n;

    std::vector<std::pair<int, int>> signals;
    signals.reserve(n);

    for (int i = 0; i < n; ++i)
    {
        int xi, di;
        std::cin >> xi >> di;
        signals.push_back({xi - di, xi + di});
    }

    std::cout << findIntersection(signals, n) << std::endl;

    return 0;
}