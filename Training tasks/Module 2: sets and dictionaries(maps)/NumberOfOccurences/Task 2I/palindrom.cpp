#include <bits/stdc++.h>

using namespace std;

// #define LOCAL

void wrap(const string& input){
    ifstream inputFile(input);

    int n;
    inputFile >> n;

    map<char, int> letters;
    char bufChar;
    //заполняем словарь, где ключ - латинская буква, 
    //значение - число появлений во вводе 
    for (int i = 0; i < n; ++i)
    {
        inputFile >> bufChar;
        ++letters[bufChar];
    }

    //нам нужен первы в алфавитном порядке
    //из самых длинных палиндромов:
    // AXSASXA вместо AXSBSXA

    string palindrome;
    //средний символ будем хранить отдельно
    //по описанной выше причине
    char middleChar;
    bool isMiddle = false;

    auto it = letters.begin();
    auto itEnd = letters.end();

    //указатель на место результирующей строки, 
    //куда вставлять символы
    size_t midPointer = 0;

    while (it != itEnd) {
        int charQuantity = it->second;
        char bufChar = it->first;
        
        if (charQuantity % 2 != 0)
        {
            //доводим количество до чётного значения
            --charQuantity;
            // если количество нечётное, то самую раннюю букву
            // из "нечётных" сохраняем для среднего символа
            if (!isMiddle)
            {
                isMiddle = true;
                middleChar = bufChar;
            }
        }
        while (charQuantity > 0) {
            //дозапиываем две буквы, а указатель среднего положения сдвигаем на 1
            palindrome.insert(midPointer, 2, bufChar);
            ++midPointer;

            charQuantity -= 2;
        }

        ++it;
    }

    //если в принципе есть средняя буква, дописываем её
    if (isMiddle) {
        palindrome.insert(midPointer, 1, middleChar);
    }

    cout << palindrome << endl;
}

// void test(){}

int main()
{
#ifdef LOCAL
    ifstream inputFile("test.txt");
    // объявить те же переменные, что и в основной части

    while ()
    {
        test();
    }
#else
    string input = "input.txt";
    wrap(input);
    
#endif

    return 0;
}