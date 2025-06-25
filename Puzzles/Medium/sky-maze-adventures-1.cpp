// https://www.codingame.com/training/medium/sky-maze-adventures-1

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>

using namespace std;

#define H real()
#define W imag()
using Coord = complex<int>;

vector<pair<Coord, string>> dd = { {{-1, 0}, "UP"}, {{1, 0}, "DOWN"}, {{0, -1}, "LEFT"}, {{0, 1}, "RIGHT"} };

struct PathInfo {
    Coord from;
    string direction;
};

int main()
{
    int w, h;
    cin >> w >> h;
    int dx, dy;
    cin >> dx >> dy;

    vector<string> maze(h);
    for (auto& line : maze)
        cin >> line;

    // reading first position  and calculate whole solution
    int x, y;
    cin >> x >> y;
    Coord start{ y, x };
    Coord finish{ dy, dx };

    vector<vector<PathInfo>> path(h, vector<PathInfo>(w));
    path[start.H][start.W] = { {0, 0}, "" };
    maze[start.H][start.W] = '2';

    queue<Coord> q;
    q.push(start);
    bool finishReached = false;
    while (!finishReached) {
        auto coord = q.front(); q.pop();
        for (auto [d, direction] : dd) {
            auto c = coord + d;
            if (c.H >= 0 && c.W >= 0 && c.H < h && c.W < w && maze[c.H][c.W] == '0') {
                path[c.H][c.W] = { coord, direction };
                maze[c.H][c.W] = '2';
                q.push(c);
                if (c == finish)
                    finishReached = true;
            }
        }
    }
    stack<string> directions;
    for (auto coord = finish; coord != start; coord = path[coord.H][coord.W].from)
        directions.push(path[coord.H][coord.W].direction);
    cout << directions.top() << endl; directions.pop();

    // game loop
    while (!directions.empty()) {
        int x, y;
        cin >> x >> y;
        cout << directions.top() << endl; directions.pop();
    }
}
