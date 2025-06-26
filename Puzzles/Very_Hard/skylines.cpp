// https://www.codingame.com/training/expert/skylines

#include <iostream>

using namespace std;

// Short range of input values. Just brute force it.

int main()
{
    constexpr int max_length = 5001;
    int heights[max_length] = { 0 };

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, x_1, x_2;
        cin >> h >> x_1 >> x_2;
        for (int x = x_1; x < x_2; x++)
            heights[x] = max(heights[x], h);
    }

    int lines = 0;
    for (int i = 0, prev_h = 0; i < max_length; i++) {
        if (heights[i] != prev_h) {
            prev_h = heights[i];
            lines += 2;    // vertical + horizontal line
        }
    }

    cout << lines - 1 << endl; // removing last horizontal line
}
