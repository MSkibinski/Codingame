// https://www.codingame.com/training/easy/furlongs-per-fortnight

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

const vector<pair<string, int>> distanceCT{ {"miles", 8}, {"furlongs", 10}, {"chains", 22}, {"yards", 3}, {"feet", 12}, {"inches", 0} };
const vector<pair<string, int>> timeCT{ {"fortnight", 2}, {"week", 7}, {"day", 24}, {"hour", 60}, {"minute", 60}, {"second", 0} };

pair<int, bool> conversionValue(const string& key1, const string key2, const vector<pair<string, int>>& ct) {
    bool isMultiplication = true;

    auto it1 = find_if(ct.begin(), ct.end(), [&](auto& e) {return e.first == key1; });
    auto it2 = find_if(ct.begin(), ct.end(), [&](auto& e) {return e.first == key2; });

    if (it2 < it1) {
        isMultiplication = false;
        swap(it1, it2);
    }

    int value = accumulate(it1, it2, 1, [&](auto& a, auto& b) {return a * b.second; });
    return { value, isMultiplication };
}

int main()
{
    double value;
    string dist1, dist2, time1, time2, s;
    cin >> value >> dist1 >> s >> time1 >> s >> s >> dist2 >> s >> time2;

    auto distanceConversion = conversionValue(dist1, dist2, distanceCT);
    auto timeConversion = conversionValue(time1, time2, timeCT);

    value = (distanceConversion.second ? value * distanceConversion.first : value / distanceConversion.first);
    value = (timeConversion.second ? value / timeConversion.first : value * timeConversion.first);

    cout << setprecision(1) << std::fixed;
    cout << value << " " << dist2 << " per " << time2 << endl;
}
