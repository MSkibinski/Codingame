// https://www.codingame.com/training/medium/minimax-exercise

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

constexpr int minusInf = numeric_limits<int>::min();
constexpr int plusInf = numeric_limits<int>::max();
int maxDepth, b;
int visitedNodes = 0;
vector<int> nodes;
int nId = 0;

int minimaxWithAlphabeta(int depth, int alpha, int beta, bool maximizeResult) {
    visitedNodes++;
    if (depth == maxDepth)
        return nodes[nId++];
    if (maximizeResult) {
        int value = minusInf;
        for (int i = 0; i < b; i++) {
            value = max(value, minimaxWithAlphabeta(depth + 1, alpha, beta, false));
            if (value >= beta) {
                nId += (b - i - 1) * pow(b, maxDepth - depth - 1); // moving through cutoff nodes;
                break;
            }
            alpha = max(alpha, value);
        }
        return value;
    }
    else {
        int value = plusInf;
        for (int i = 0; i < b; i++) {
            value = min(value, minimaxWithAlphabeta(depth + 1, alpha, beta, true));
            if (value <= alpha) {
                nId += (b - i - 1) * pow(b, maxDepth - depth - 1); // moving through cutoff nodes;
                break;
            }
            beta = min(beta, value);
        }
        return value;
    }
}

int main()
{
    cin >> maxDepth >> b;

    nodes.resize(pow(b, maxDepth));
    for (auto& node : nodes)
        cin >> node;

    bool maximizeResult = true;
    auto bestResult = minimaxWithAlphabeta(0, minusInf, plusInf, maximizeResult);

    cout << bestResult << " " << visitedNodes << endl;
}
