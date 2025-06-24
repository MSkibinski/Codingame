// https://www.codingame.com/training/easy/tile-a-floor

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char oppositeRight[128];
char oppositeDown[128];

void init() {
    for (int i = 0; i < 128; i++) {
        oppositeRight[i] = i;
        oppositeDown[i] = i;
    }
    oppositeRight['('] = ')'; oppositeRight[')'] = '(';
    oppositeRight['{'] = '}'; oppositeRight['}'] = '{';
    oppositeRight['['] = ']'; oppositeRight[']'] = '[';
    oppositeRight['<'] = '>'; oppositeRight['>'] = '<';
    oppositeRight['/'] = '\\'; oppositeRight['\\'] = '/';

    oppositeDown['^'] = 'v'; oppositeDown['v'] = '^';
    oppositeDown['A'] = 'V'; oppositeDown['V'] = 'A';
    oppositeDown['w'] = 'm'; oppositeDown['m'] = 'w';
    oppositeDown['W'] = 'M'; oppositeDown['M'] = 'W';
    oppositeDown['u'] = 'n'; oppositeDown['n'] = 'u';
    oppositeDown['/'] = '\\'; oppositeDown['\\'] = '/';
}

int main()
{
    init();

    int n;
    cin >> n; cin.ignore();

    vector<string> rows(2 * n - 1, string(2 * n - 1, ' '));
    for (int i = 0; i < n; i++) {
        getline(cin, rows[i]);
        rows[i].resize(2 * n - 1);

        for (int j = 0; j < n; j++) {
            rows[i][2 * n - 2 - j] = oppositeRight[rows[i][j]];
            rows[2 * n - 2 - i][j] = oppositeDown[rows[i][j]];
            rows[2 * n - 2 - i][2 * n - 2 - j] = oppositeDown[oppositeRight[rows[i][j]]];
        }
    }

    string grout(4 * n + 1, '-');
    grout[0] = grout[2 * n] = grout[4 * n] = '+';

    for (int k = 0; k < 2; k++) {
        cout << grout << endl;
        for (int i = 0; i < rows.size(); i++)
            cout << '|' << rows[i] << '|' << rows[i] << '|' << endl;
    }
    cout << grout << endl;
}
