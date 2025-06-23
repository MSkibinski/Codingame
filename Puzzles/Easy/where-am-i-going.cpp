// https://www.codingame.com/training/easy/where-am-i-going

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

using Point = complex<int>;
#define H real()
#define W imag()

class Field {
    vector<string> t;

public:
    void read() {
        int h, w;
        cin >> h >> w;
        for (string s; h > 0; h--) {
            cin >> s;
            t.push_back(s);
        }
    }

    char get(Point p) {
        if (p.H < 0 || p.H >= t.size() || p.W < 0 || p.W >= t[0].size())
            return ' ';
        return t[p.H][p.W];
    }
};

void describePath(Field& field) {
    vector<Point> dir{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 0-right, 1-down, 2-left, 3-up
    Point pos(0, -1);
    int direction = 0;
    int steps = 0;

    // i represents change of direction relative to our current direction -1 = turn left, 0 = continue, 1 = turn right
    for (int i = -1; i <= 1; i++) {
        Point next_pos = pos + dir[(direction + dir.size() + i) % 4];
        if (field.get(next_pos) == '#') {
            pos = next_pos;
            if (i == 0) {
                steps++;
            }
            else {
                direction = (direction + dir.size() + i) % 4;
                cout << steps << (i == -1 ? 'L' : 'R');
                steps = 1;
            }
            i = -2; // reset for loop. Next step will start with i=-1
        }
    }
    cout << steps << endl;
}

int main()
{
    Field field;
    field.read();

    describePath(field);
}
