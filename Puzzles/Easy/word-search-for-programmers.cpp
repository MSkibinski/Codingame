// https://www.codingame.com/training/easy/word-search-for-programmers

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> grid;
vector<string> result;

bool check(const string& word, int x, int y, int dx, int dy) {
    int startX = x;
    int startY = y;

    for (int i = 0; i < word.size(); i++, x += dx, y += dy)
        if (word[i] != grid[y][x])
            return false;

    for (int i = 0, x = startX, y = startY; i < word.size(); i++, x += dx, y += dy)
        result[y][x] = word[i];

    return true;;
}

int main()
{
    int size;
    cin >> size;

    grid.resize(size);
    for (auto& line : grid)
        cin >> line;
    result = vector<string>(size, string(size, ' '));

    string word;
    while (cin >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::toupper);
        bool found = false;
        int len = word.size();
        for (int y = 0; y < size && !found; y++) {
            for (int x = 0; x < size && !found; x++) {
                if (grid[y][x] != word[0]) continue;

                if (x + len <= size)                              found = check(word, x, y, 1, 0);
                if (!found && x + 1 - len >= 0)                     found = check(word, x, y, -1, 0);
                if (!found && y + len <= size)                    found = check(word, x, y, 0, 1);
                if (!found && y + 1 - len >= 0)                     found = check(word, x, y, 0, -1);
                if (!found && x + len <= size && y + len <= size)   found = check(word, x, y, 1, 1);
                if (!found && x + len <= size && y + 1 - len >= 0)    found = check(word, x, y, 1, -1);
                if (!found && x + 1 - len >= 0 && y + len <= size)    found = check(word, x, y, -1, 1);
                if (!found && x + 1 - len >= 0 && y + 1 - len >= 0)     found = check(word, x, y, -1, -1);
            }
        }
    }

    for (auto& line : result)
        cout << line << endl;
}
