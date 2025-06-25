// https://www.codingame.com/training/hard/thomas-and-the-freight-cars

#include <iostream>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

template <typename Comparator>
int calculate(set<pair<int, int>, Comparator>& s, int w, Comparator comp) {
    auto it = upper_bound(s.begin(), s.end(), make_pair(w, 0), comp);
    auto p = it == s.end() ? 0 : it->second + 1;
    if (it == s.end()) {
        if (s.size())
            s.erase(--s.end());
    }
    else if (it != s.begin()) {
        --it;
        s.erase(it);
    }
    s.insert({ w, p });
    return p;
}

int main()
{
    int N, p_max = 0;
    cin >> N;

    list<int> weight;
    set<pair<int, int>> lighter;
    set<pair<int, int>, greater<pair<int, int>>> heavier;

    while (cin >> N)
        weight.push_front(N);
    for (auto w : weight)
        p_max = max(p_max, calculate(lighter, w, less<pair<int, int>>()) + calculate(heavier, w, greater<pair<int, int>>()) + 1);
    cout << p_max << endl;
}
