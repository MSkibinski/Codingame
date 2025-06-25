// https://www.codingame.com/training/easy/create-turn-here-signs

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string direction;
    int nrOfArr, height, width, spacing, addIndent;

    cin >> direction >> nrOfArr >> height >> width >> spacing >> addIndent;

    string arrowLayer(width, direction == "right" ? '>' : '<');
    string line = arrowLayer;
    for (int i = 1; i < nrOfArr; i++)
        line += string(spacing, ' ') + arrowLayer;

    int indent = 0;
    if (direction == "left") {
        indent = height / 2 * addIndent;
        addIndent *= -1;
    }
    for (int i = 0; i < height; i++) {
        cout << string(indent, ' ') << line << endl;
        if (i == height / 2)
            addIndent *= -1;
        indent += addIndent;
    }
}
