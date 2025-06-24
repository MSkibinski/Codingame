// https://www.codingame.com/training/hard/hexagonal-maze---part2

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <queue>
#include <complex>

using namespace std;

#define H real()
#define W imag()
using Coord = complex<int>;

int createHash(const Coord& coord, const bitset<4>& keys) {
    return coord.H * 10000 + coord.W * 100 + keys.to_ulong() + 1;
}

struct State {
    Coord coord;
    bitset<4> keys;
    string dirName;
    int prevStateHash;

    int getHash() { return createHash(coord, keys); }
};

class Grid {
    const int width;
    const int height;
    vector<string> symbols;
    map<int, State> states;
    int finish;

    bool isDoor(char symbol) { return symbol >= 'A' && symbol <= 'D'; }
    bool isKey(char symbol) { return symbol >= 'a' && symbol <= 'd'; }
    bool canOpen(char doorSymbol, const bitset<4>& keys) { return keys[doorSymbol - 'A']; }
    bool blocked(char symbol, const bitset<4>& keys) {
        return symbol == '#' || (isDoor(symbol) && !canOpen(symbol, keys));
    }
    void addKey(bitset<4>& keys, char symbol) { keys.set(symbol - 'a'); }
    bool stateVisited(State& state) { return state.coord != Coord{}; }

    string getDirectionsToNode(int nodeHash) {
        auto state = states[nodeHash];
        return state.dirName.empty() ? "" : getDirectionsToNode(state.prevStateHash) + " " + state.dirName;
    }

public:
    Grid(int w, int h) : width(2 * w), height(h), symbols(height, string(width, ' ')) {
        for (int i = 0; i < height; i++) {
            string row;
            cin >> row;
            for (int j = 0, sj = i % 2; j < row.size(); j++, sj += 2) {
                symbols[i][sj] = row[j];
                if (row[j] == 'S') {
                    State start = { {i, sj}, {} };
                    states[start.getHash()] = start;
                }
            }
        }
    }

    void findShortestPath() {
        queue<int> toVisit;
        toVisit.push(states.begin()->first);

        const map<string, Coord> directions{ {"DL", {1, -1}}, {"DR", {1, 1}}, {"R", {0, 2}}, {"UR", {-1, 1}}, {"UL", {-1, -1}}, {"L", {0, -2}} };
        while (true) {
            auto state = states[toVisit.front()]; toVisit.pop();
            for (auto& [dirName, dirValue] : directions) {
                auto keys = state.keys;
                auto nextCoord = state.coord + dirValue;
                auto symbol = symbols[nextCoord.H][nextCoord.W];
                if (blocked(symbol, keys)) continue;

                if (symbol == '_') {  // slide
                    auto nc = nextCoord + dirValue;
                    while (symbols[nc.H][nc.W] == '_') {
                        nextCoord = nc;
                        nc += dirValue;
                    }
                    auto nextSymbol = symbols[nc.H][nc.W];
                    if (!blocked(nextSymbol, keys)) {
                        nextCoord = nc;
                        symbol = nextSymbol;
                    }
                }
                if (isKey(symbol))
                    addKey(keys, symbol);

                auto nextStateHash = createHash(nextCoord, keys);
                auto& nextState = states[nextStateHash];
                if (stateVisited(nextState)) continue;

                nextState = { nextCoord, keys, dirName, state.getHash() };
                if (symbol == 'E') {
                    finish = nextStateHash;
                    return;
                }
                toVisit.push(nextStateHash);
            }
        }
    }

    void printDirections() {
        cout << getDirectionsToNode(finish).substr(1);
    }

    void debugPrintGrid() {
        for (auto& row : symbols)
            cerr << row << endl;
    }
};

int main()
{
    int w, h;
    cin >> w >> h;

    Grid grid(w, h);
    grid.debugPrintGrid();
    grid.findShortestPath();
    grid.printDirections();
}
