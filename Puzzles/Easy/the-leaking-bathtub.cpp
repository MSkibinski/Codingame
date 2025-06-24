// https://www.codingame.com/training/easy/the-leaking-bathtub

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int s, h, curr_flow, n;
    cin >> s >> h >> curr_flow >> n;

    vector<pair<int, int>> leaks(n);
    for (auto& [height, flow] : leaks)
        cin >> height >> flow;
    leaks.push_back({ h, 0 }); // virtual 0 leak at the top of bathtub to simplify calculations

    sort(leaks.begin(), leaks.end());

    int curr_height = 0;
    float filling_time_sec = 0;
    for (auto& [height, flow] : leaks) {
        if (height > curr_height) {
            int volume = s * (height - curr_height);
            filling_time_sec += volume * 60.0 / 1000 / curr_flow; // conversion from L/min into cm3/s
        }
        curr_height = height;
        curr_flow -= flow;
        if (curr_flow <= 0) {
            cout << "Impossible, " << curr_height << " cm." << endl;
            return 0;
        }
    }

    int seconds(filling_time_sec);
    int hours = seconds / 3600;
    seconds -= hours * 3600;
    int minuts = seconds / 60;
    seconds -= minuts * 60;

    cout << setfill('0') << std::setw(2) << hours << ":" << setfill('0') << std::setw(2) << minuts << ":" << setfill('0') << std::setw(2) << seconds << endl;
}
