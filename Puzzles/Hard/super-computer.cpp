// https://www.codingame.com/training/hard/super-computer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> reservation(n);
    for (int i = 0; i < n; i++)
        cin >> reservation[i].first >> reservation[i].second;
    sort(reservation.begin(), reservation.end());

    int nextFree = INT32_MAX;
    int result = 1;
    for (auto& r : reservation) {
        if (r.first >= nextFree) {
            result++;
            nextFree = r.first + r.second;
        }
        else {
            nextFree = min(nextFree, r.first + r.second);
        }
    }

    cout << result << endl;
}
