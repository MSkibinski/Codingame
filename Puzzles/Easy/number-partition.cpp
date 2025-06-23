// https://www.codingame.com/training/easy/number-partition

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void partition(int n, vector<int>& v) {
    if (n == 0) {
        string sep = "";
        for (auto e : v) {
            cout << sep << e; sep = " ";
        }
        cout << endl;
        return;
    }

    int last_elem = v.size() ? v.back() : n;
    for (int i = min(n, last_elem); i > 0; i--) {
        v.push_back(i);
        partition(n - i, v);
        v.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    partition(n, v);
}
