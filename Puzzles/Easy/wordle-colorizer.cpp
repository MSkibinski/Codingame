// https://www.codingame.com/training/easy/wordle-colorizer

#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int len = 5;
constexpr char blank = '-';

int main()
{
    string answer, attempt;
    int n;

    cin >> answer >> n;

    vector<int> counter(128);
    for (auto letter : answer)
        counter[letter]++;

    while (n--) {
        string result(len, blank);
        auto c = counter;

        cin >> attempt;
        for (int i = 0; i < len; i++) {
            if (attempt[i] == answer[i]) {
                c[attempt[i]]--;
                result[i] = '#';
            }
        }
        for (int i = 0; i < len; i++) {
            if (result[i] != blank)
                continue;

            if (c[attempt[i]]) {
                c[attempt[i]]--;
                result[i] = 'O';
            }
            else
                result[i] = 'X';
        }
        cout << result << endl;
    }
}
