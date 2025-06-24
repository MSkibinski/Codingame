// https://www.codingame.com/training/hard/the-hungry-duck---part-2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w, h;
    cin >> w >> h;

    vector<int> f(w + 1);
    while (h--) {
        for (int i = 1; i <= w; i++) {
            int food;
            cin >> food;
            f[i] = max(f[i], f[i - 1]) + food;
        }
    }

    cout << f.back() << endl;
}
