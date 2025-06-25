// https://www.codingame.com/training/medium/hacking-at-robbercity

#include <iostream>
#include <string>

using namespace std;

int h2d(char c) {
    return isdigit(c) ? c - '0' : c - 'a' + 10;
}

int hexToDec(char c1, char c2) {
    return h2d(c1) * 16 + h2d(c2);
}

int main()
{
    string m1, m2, m3;
    cin >> m1 >> m2 >> m3;

    for (int i = 0; i < m1.size(); i += 2) {
        int v1 = hexToDec(m1[i], m1[i + 1]);
        int v2 = hexToDec(m2[i], m2[i + 1]);
        int v3 = hexToDec(m3[i], m3[i + 1]);
        cout << char(v1 ^ v2 ^ v3);
    }
}
