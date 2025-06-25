// https://www.codingame.com/training/easy/ascii-art-the-drunken-bishop-algorithm

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
    const int max_x = 17;
    const int max_y = 9;
    int x = 8;
    int y = 4;

    string to_char = " .o+=*BOX@%&#/^";

    int timesVisited[max_y][max_x] = { 0 };

    for (string group; getline(cin, group, ':');) {
        auto bitGroup = bitset<8>(stoi(group, 0, 16)).to_string();
        for (int i = 3; i >= 0; i--) {
            auto bitPair = bitGroup.substr(i * 2, 2);

            if (bitPair[0] == '0') y = max(y - 1, 0);
            else y = min(y + 1, max_y - 1);
            if (bitPair[1] == '0') x = max(x - 1, 0);
            else x = min(x + 1, max_x - 1);

            timesVisited[y][x]++;
        }
    }

    cout << "+---[CODINGAME]---+" << endl;
    for (int h = 0; h < max_y; h++) {
        cout << '|';
        for (int w = 0; w < max_x; w++) {
            if (w == x && h == y) cout << "E";
            else if (w == 8 && h == 4) cout << "S";
            else cout << to_char[timesVisited[h][w] % 15];
        }
        cout << '|' << endl;
    }
    cout << "+-----------------+" << endl;
}
