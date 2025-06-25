// https://www.codingame.com/training/hard/the-greatest-number

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    bool dot = false, minus = false;
    vector<char> digits;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        switch (c) {
        case '.': dot = true; break;
        case '-': minus = true; break;
        default:
            digits.push_back(c);
        }
    }
    sort(digits.begin(), digits.end(), greater<char>());
    if (*digits.begin() == '0' && *digits.rbegin() == '0')
        cout << "0" << endl, exit(0);

    if (dot)
        digits.insert(digits.end() - 1, '.');

    if (minus) {
        cout << "-";
        reverse(digits.begin(), digits.end());
    }
    else if (dot && *digits.rbegin() == '0')
        digits.erase(digits.end() - 2, digits.end());

    for (auto c : digits)
        cout << c;
}
