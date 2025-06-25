// https://www.codingame.com/training/easy/make-an-atari-font

#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    vector<bitset<64>> letters_hex = { 0x1818243C42420000, 0x7844784444780000, 0x3844808044380000, 0x7844444444780000, 0x7C407840407C0000, 0x7C40784040400000,
                  0x3844809C44380000, 0x42427E4242420000, 0x3E080808083E0000, 0x1C04040444380000, 0x4448507048440000, 0x40404040407E0000, 0x4163554941410000,
                  0x4262524A46420000, 0x1C222222221C0000, 0x7844784040400000, 0x1C222222221C0200, 0x7844785048440000, 0x1C22100C221C0000, 0x7F08080808080000,
                  0x42424242423C0000, 0x8142422424180000, 0x4141495563410000, 0x4224181824420000, 0x4122140808080000, 0x7E040810207E0000 };

    vector<string> letters;
    for (auto& letter : letters_hex)
        letters.push_back(letter.to_string(' ', 'X'));

    string a_word;
    getline(cin, a_word);

    for (int row = 0; row < 8; row++) {
        string result_line;
        for (auto letter : a_word)
            result_line += letters[letter - 'A'].substr(row * 8, 8);
        if (auto pos = result_line.rfind('X'); pos != string::npos)
            cout << result_line.substr(0, pos + 1) << endl;
    }
}
