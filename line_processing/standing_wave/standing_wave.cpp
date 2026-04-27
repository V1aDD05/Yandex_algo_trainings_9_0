#include <iostream>
#include <vector>
#include <tuple>

std::vector<std::tuple<long long int, long long int, int>> enterOccasions(const int n)
{
    std::vector<std::tuple<long long int, long long int, int>> result;
    result.reserve(n);

    for (size_t i = 0; i < n; ++i)
    {
        long long int li, ri;
        int xi;
        std::cin >> li >> ri >> xi;
        result.push_back({li, ri, xi});
    }
    return result;
}

std::vector<long long int> enterRequests(const int m) 
{
    std::vector<long long int> result;
    result.reserve(m);

    for (size_t j = 0; j < m; ++j)
    {
        int xi;
        std::cin >> xi;
        result.push_back(xi);
    }

    return result;
}

std::vector<long long int> detectHeights(const std::vector<std::tuple<long long int, long long int, int>> &occasion, const std::vector<long long int> &interestingParts)
{
    size_t m = interestingParts.size();
    size_t n = occasion.size();

    std::vector<long long int> result;
    result.reserve(m);

    for (size_t i = 0; i < m; ++i)
    {
        //для каждого из m инетересующих положений будем считать результирущее воздейтвие 
        long long int position = interestingParts[i];
        long long int resSum = 0;

        for (size_t j = 0; j < n; ++j){
            
            long long int li = std::get<0>(occasion[j]);
            long long int ri = std::get<1>(occasion[j]); //создали для однообразия
            // если position попадает в область n-ого события
            if (li <= position && ri >= position)
            {   
                //прибавляем xi с нужным знаком
                if ((position-li) % 2 == 0) {
                    resSum += std::get<2>(occasion[j]);
                }
                else {
                    resSum -= std::get<2>(occasion[j]);
                }
            }
        }
        result.push_back(resSum);
    }
    
    return result;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::tuple<long long int, long long int, int>> occasion = enterOccasions(n);

    std::vector<long long int> interestingParts = enterRequests(m);

    std::vector<long long int> result = detectHeights(occasion, interestingParts);

    for (int i = 0; i < m; ++i) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}