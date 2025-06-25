// https://www.codingame.com/training/medium/kids-blocks

#include <iostream>

using namespace std;

int main()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int total = x1 + 2 * x2 + 3 * x3;
    int min_width = (x3 ? 3 : (x2 ? 2 : 1));
    int max_width = total / 2;
    int possible_odd_lines = x1 + x3;

    for (int w = min_width; w <= max_width; w++) {
        if (total % w)
            continue;
        int h = total / w;

        int x3_per_line = w / 3;
        if (h * x3_per_line < x3)
            continue;

        int x2_per_line = w / 2;
        if (h * x2_per_line < x2)
            continue;

        if (w % 2 && h > possible_odd_lines)
            continue;

        cout << "POSSIBLE" << endl;
        return 0;
    }

    cout << "NOT POSSIBLE" << endl;
}
