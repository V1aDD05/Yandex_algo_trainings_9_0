#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int wrap(vector<vector<char>>& map) 
{
    int result = 0;
    size_t mapRaws = map.size();
    size_t mapCols = map[0].size();

    if (mapRaws == 1 && mapCols == 1) {
        return 0;
    }


    for (size_t i = 0; i < mapRaws; ++i){
        for (size_t j = 0; j < mapCols; ++j) {
            if ((i == mapRaws - 1) && (j < mapCols-1))
            {
                if (map[i][j] == '.' && map[i][j+1] == '.') {
                    ++result;
                }
            }
            else if ((j == mapCols - 1) && (i < mapRaws - 1))
            {
                if (map[i][j] == '.' && map[i+1][j] == '.') {
                    ++result;
                }
            }
            else if ((i < mapRaws - 1) && (j < mapCols - 1))
            {
                if (map[i][j] == '.' && map[i][j + 1] == '.')
                {
                    ++result;
                }
                if (map[i][j] == '.' && map[i + 1][j] == '.')
                {
                    ++result;
                }
            }
        }
    }

    return result;
}

    int main()
{
    ifstream inputFile("input.txt");

    int n, m;
    inputFile >> n >> m;
    char bufChar;
    inputFile.get(bufChar);

    vector<vector<char>> map(n, vector<char>(m));
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j) {
            inputFile.get(bufChar);
            map[i][j] = bufChar;
        }
        inputFile.get(bufChar);
    }

    int result = wrap(map);    

    cout << result << endl;
    return 0;
}