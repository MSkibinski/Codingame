// https://www.codingame.com/training/medium/jumping-frog

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

#define H real()
#define W imag()
using Coord = complex<int>;

int n;
vector<string> grid;
const char water = '.';
const char lily = '#';

int jumps = 0;
int longest_path = 0;
int total_lilies = 0;
const vector<Coord> dd{ {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {2, 0}, {-2, 0}, {0, 2}, {0, -2} };

void jump(Coord coord) {
    jumps++;
    longest_path = max(longest_path, jumps);
    if (longest_path == total_lilies) {
        cout << longest_path << endl;
        exit(0);
    }
    grid[coord.H][coord.W] = water;
    for (const auto& d : dd) {
        auto c = coord + d;
        if (c.H >= 0 && c.W >= 0 && c.H < n && c.W < n && grid[c.H][c.W] == lily)
            jump(c);
    }

    jumps--;
    grid[coord.H][coord.W] = lily;
}

int main()
{
    cin >> n;

    grid.resize(n);
    for (auto& row : grid) {
        cin >> row;
        total_lilies += count(row.begin(), row.end(), lily);
        cerr << row << endl;
    }

    int x, y;
    cin >> x >> y;
    jump({ y, x });

    cout << longest_path << endl;
}
