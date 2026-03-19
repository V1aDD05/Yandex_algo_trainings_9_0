#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string wrap(const string &input)
{
    size_t inputSize = input.size();
    string result;
    char codedChar;

    char bufChar;
    string bufString;

    for (size_t i = inputSize; i-- > 0;)
    {
        bufChar = input[i];
        if (bufChar == '#' && i >= 2)
        {
            bufString.push_back(input[i - 2]);
            bufString.push_back(input[i - 1]);
            codedChar = static_cast<char>('a' + stoi(bufString) - 1);
            bufString.clear();
            i -= 2;
        }
        else
        {
            codedChar = static_cast<char>('a' + (bufChar - '0') - 1);
        }
        result.push_back(codedChar);
    }

    return result;
}

int main()
{
    ifstream inputFile("input.txt");

    string input;
    getline(inputFile, input);

    string result = wrap(input);

    size_t resSize = result.size();
    for (size_t j = resSize; j-- > 0;)
    {
        cout << result[j];
    }
    cout << endl;

    return 0;
}
