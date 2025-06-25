// https://www.codingame.com/training/medium/shikaku-solver

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ShikakuSolver {
    int height;
    int width;
    int solutions = 0;

    vector<vector<int>> grid;
    vector<string> solution;
    vector<string> firstSolution;
    const char emptyLetter = '-';

    bool findEmptyCellInSolution(int& emptyCell_h, int& emptyCell_w) {
        for (; emptyCell_h < height; emptyCell_h++, emptyCell_w = 0)
            for (; emptyCell_w < width; emptyCell_w++)
                if (solution[emptyCell_h][emptyCell_w] == emptyLetter)
                    return true;
        return false;
    }

    bool rectanglePossible(int h1, int h2, int w1, int w2) {
        int size_fields = 0;
        for (int i = h1; i <= h2; i++)
            for (int j = w1; j <= w2; j++) {
                // possible rectangle cann't override other rectangle
                if (solution[i][j] != emptyLetter)
                    return false;
                // possible rectangle has one field with size description
                if (grid[i][j] && size_fields++)
                    return false;
            }
        return true;
    }

    void solve(int emptyCell_h, int emptyCell_w, char currLetter) {
        if (!findEmptyCellInSolution(emptyCell_h, emptyCell_w)) {
            solutions++;
            if (solutions == 1)
                firstSolution = solution;
            return;
        }

        // looking for reachable fields with rectangle size information
        for (int h = emptyCell_h, rightBorder = width; h < height; h++)
            for (int w = emptyCell_w; w < rightBorder; w++) {
                if (solution[h][w] != emptyLetter) {
                    rightBorder = w;
                    break;
                }
                if (int sizeToFind = grid[h][w]) {
                    for (int w2 = w + 1; w2 < rightBorder; w2++)
                        if (solution[h][w2] != emptyLetter || grid[h][w2])
                            rightBorder = w2;
                    // searching for all possible rectangles with given size
                    for (int h2 = h; h2 < height; h2++) {
                        int rect_height = h2 - emptyCell_h + 1;
                        if (rect_height > sizeToFind) break;
                        if (sizeToFind % rect_height) continue;

                        int required_width = sizeToFind / rect_height;
                        if (required_width < w - emptyCell_w + 1) break;
                        if (rectanglePossible(emptyCell_h, h2, emptyCell_w, emptyCell_w + required_width - 1)) {
                            for (int i = emptyCell_h; i <= h2; i++)
                                solution[i].replace(emptyCell_w, required_width, string(required_width, currLetter));
                            auto nextLetter = currLetter == 'Z' ? 'a' : currLetter + 1;
                            solve(emptyCell_h, emptyCell_w, nextLetter);
                            for (int i = emptyCell_h; i <= h2; i++)
                                solution[i].replace(emptyCell_w, required_width, string(required_width, emptyLetter));
                        }
                    }
                    rightBorder = w;
                }
            }
    }

public:
    void init() {
        cin >> width >> height;

        grid.resize(height, vector<int>(width));
        for (auto& row : grid)
            for (auto& elem : row)
                cin >> elem;
        solution.resize(height, string(width, emptyLetter));
    }

    void solve() {
        solve(0, 0, 'A');
    }

    void printSolution() {
        cout << solutions << endl;
        for (auto& row : firstSolution)
            cout << row << endl;
    }
};

int main()
{
    ShikakuSolver shikakuSolver;
    shikakuSolver.init();
    shikakuSolver.solve();
    shikakuSolver.printSolution();
}
