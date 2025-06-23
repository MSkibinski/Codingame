// https://www.codingame.com/training/easy/queen-control

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string color;
    cin >> color;

    vector<string> board(8);
    int q_i, q_j;
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
        if (auto pos = board[i].find('Q'); pos != string::npos) {
            q_i = i;
            q_j = pos;
        }
    }

    int result = 0;
    for (auto di : { -1, 0, 1 }) {
        for (auto dj : { -1, 0, 1 }) {
            int i = q_i;
            int j = q_j;
            while (true) {
                i += di;
                j += dj;
                if (i < 0 || i>7 || j < 0 || j>7) break;
                if (board[i][j] == '.')
                    result++;
                else {
                    if (board[i][j] != 'Q' && board[i][j] != color[0])
                        result++;
                    break;
                }
            }
        }
    }

    cout << result << endl;
}
