#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <unordered_map>

using namespace std;

vector<long long int> wrap(const vector<tuple<long long int, long long int, int>> &occasion, const vector<long long int>& interestingParts){
    size_t m = interestingParts.size();
    size_t n = occasion.size();

    vector<long long int> result;

    for (size_t i = 0; i < m; ++i)
    {
        //для каждого из m инетересующих положений будем считать префиксную сумму
        long long int position = interestingParts[i];
        long long int prefSum = 0;


        for (size_t j = 0; j < n; ++j){
            
            long long int li = get<0>(occasion[j]);
            long long int ri = get<1>(occasion[j]); //создали для однообразия
            // если position попадает в область n-ого события
            if (li <= position && ri >= position)
            {   
                //прибавляем xi с нужным знаком
                if ((position-li) % 2 == 0) {
                    prefSum += get<2>(occasion[j]);
                }
                else {
                    prefSum -= get<2>(occasion[j]);
                }
            }
        }
        result.push_back(prefSum);
    }
    
    return result;
}

    int main()
{
    ifstream inputFile("input.txt");
    int n, m;
    inputFile >> n >> m;
    
    vector<tuple<long long int, long long int, int>> occasion(n);

    long long int li, ri;
    int xi;

    for (size_t i = 0; i < n; ++i)
    {
        inputFile >> li >> ri >> xi;
        occasion[i] = make_tuple(li, ri, xi);
    }

    vector<long long int> interestingParts(m);
    for (size_t j = 0; j < m; ++j){
        inputFile >> xi;
        interestingParts[j] = xi;
    }

    vector<long long int> result = wrap(occasion, interestingParts);

    int k = result.size();

    for (int i = 0; i < k; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}