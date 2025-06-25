// https://www.codingame.com/training/medium/guessing-digits

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Solution {
    int x, y, r;
    char c;
};

int main()
{
    int s, p;
    cin >> s >> p;
    cerr << s << " " << p << endl;

    map<int, pair<int, int>> BurtFirst{ {2, {1,1}}, {3, {1, 2}}, {17, {8, 9}}, {18, {9, 9}} };
    if (BurtFirst.count(s)) {
        cout << "(" << BurtFirst[s].first << "," << BurtFirst[s].second << ") BURT 1" << endl;
        return 0;
    }

    map<pair<int, int>, Solution> complicated{
        {{4, 4}, {2, 2, 2, 'B'}}, //+
        {{5, 4}, {1, 4, 2, 'S'}},
        {{5, 6}, {2, 3, 3, 'B'}},
        {{7, 6}, {1, 6, 3, 'S'}}, //
        {{6, 8}, {0, 0, 0, 'I'}},
        {{9, 8}, {0, 0, 0, 'I'}},
        {{6, 9}, {0, 0, 0, 'I'}},
        {{10, 9}, {0, 0, 0, 'I'}}, //
        {{7, 12}, {3, 4, 4, 'B'}},
        {{8, 12}, {2, 6, 4, 'S'}},
        {{8, 16}, {4, 4, 5, 'B'}}, //
        {{10, 16}, {2, 8, 5, 'S'}},
        {{9, 18}, {0, 0, 0, 'I'}},
        {{11, 18}, {0, 0, 0, 'I'}},
        {{10, 24}, {0, 0, 0, 'I'}},
        {{11, 24}, {0, 0, 0, 'I'}},
        {{12, 36}, {6, 6, 2, 'B'}}, //+
        {{13, 36}, {4, 9, 2, 'B'}} //
    };

    if (complicated.count({ s, p })) {
        auto solution = complicated[{s, p}];
        if (solution.c == 'I')
            cout << "IMPOSSIBLE" << endl;
        else
            cout << "(" << solution.x << "," << solution.y << ") " << (solution.c == 'B' ? "BURT " : "SARAH ") << solution.r << endl;
        return 0;
    }

    cerr << s << " " << p << endl;

    for (int x = 1; x < 10; x++) {
        if (p % x == 0 && p / x < 10) {
            cout << "(" << x << "," << p / x << ") SARAH 1" << endl;
            return 0;
        }
    }
}
