// https://www.codingame.com/training/easy/number-formatting

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string numbertext;
    getline(cin, numbertext);

    auto digitId = numbertext.find_first_not_of(",.x");

    // maybe instead if "id" I should use iterator
    bool prevOdd = false;
    if (digitId != string::npos && numbertext[digitId] == '1') {
        numbertext[digitId] = 'x';
        prevOdd = true;
        digitId++;;
    }

    for (; digitId < numbertext.size() && numbertext[digitId] != 'x'; digitId++) {
        if (isdigit(numbertext[digitId])) {
            int value = numbertext[digitId] - '0' + prevOdd * 10;
            prevOdd = value % 2;
            numbertext[digitId] = value / 2 + '0';
        }
    }

    if (prevOdd)
        numbertext[digitId] = '5';

    cout << numbertext << endl;
}
