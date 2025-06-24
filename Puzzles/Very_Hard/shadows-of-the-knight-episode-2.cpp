// https://www.codingame.com/training/expert/shadows-of-the-knight-episode-2

// One of the fastest algorithm.
// For all test cases remaining number of turns is >= 3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Range {
    int position;       // current position
    int low;            // low boundary
    int high;           // high boundary
    int maximum;        // maximum value of boundary
    int newPosition;    // calculated position

    void init(int m, int pos) {
        maximum = m - 1;
        high = maximum;
        position = pos;
        newPosition = pos;
    }
};

Range x, y;

void checkBombStatus(Range& r) {
    string bombDir;
    cin >> bombDir;

    double middle = (r.newPosition + r.position) / 2.0;
    if (bombDir == "SAME")
        r.low = r.high = middle;
    else if ((bombDir == "COLDER" && r.newPosition > r.position) ||
        (bombDir == "WARMER" && r.newPosition < r.position))
        r.high = min(r.high, int(ceil(middle - 1)));
    else
        r.low = max(r.low, int(floor(middle + 1)));

    r.position = r.newPosition;
}

void cutToHalf(Range& r) {
    if (r.low == r.high)
        return;
    double middle = (r.low + r.high) / 2.0;
    int destination = middle + (middle - r.position);

    if (destination < 0 || destination > r.maximum)
        destination = r.low + (r.high - r.low) * 3 / 5;
    else if (destination == r.position) {
        destination += (r.position < r.maximum - r.position) ? -2 : 2;
        if (destination < r.low) destination = r.low;
        if (destination > r.high) destination = r.high;
    }

    r.newPosition = destination;
    cout << x.newPosition << " " << y.newPosition << endl;
    checkBombStatus(r);

    cutToHalf(r);
}

int main()
{
    int W, H, N, startX, startY;
    cin >> W >> H >> N;

    string bombDir;
    cin >> startX >> startY >> bombDir;
    x.init(W, startX);
    y.init(H, startY);

    cutToHalf(x);
    cutToHalf(y);

    cout << x.low << " " << y.low << endl;
}
