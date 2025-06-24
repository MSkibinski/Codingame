// https://www.codingame.com/training/hard/apple-tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Apple {
    int x, y, z;
    int r;
    int id;

    bool operator<(const Apple& a) const {
        if (z != a.z) return z > a.z;
        if (x != a.x) return x > a.x;
        return y > a.y;
    }

    bool colide(const Apple& a) {
        return pow(abs(x - a.x), 2) + pow(abs(y - a.y), 2) < pow(r + a.r, 2);
    }
};

int main()
{
    int n, index;
    cin >> n >> index;

    vector<Apple> apples(n);
    for (int i = 0; i < n; i++) {
        auto& a = apples[i];
        a.id = i;
        cin >> a.x >> a.y >> a.z >> a.r;
    }
    sort(apples.begin(), apples.end());

    int i = 0;
    while (apples[i].id != index) i++;
    vector<Apple> fallingApples = { apples[i] };
    for (i++; i < n; i++)
        for (auto apple : fallingApples)
            if (apple.colide(apples[i])) {
                fallingApples.push_back(apples[i]);
                break;
            }

    cout << n - fallingApples.size() << endl;
}
