// https://www.codingame.com/training/hard/roller-coaster

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct History
{
    int rideNr;
    long long peopleRides;
};

int main()
{
    int L;
    int C;
    int N;
    cin >> L >> C >> N; cin.ignore();

    vector<pair<bool, History>> wasBefore(N);
    vector<int> group(N);
    int id = N - 1;
    long long earned = 0;

    for (int i = 0; i < N; i++) {
        cin >> group[i];
    }

    while (C--)
    {
        int peopleInCoaster = 0;
        for (int i = 0; peopleInCoaster + group[(id + 1) % N] <= L && i < N; i++)
        {
            id = (id + 1) % N;
            peopleInCoaster += group[id];
        }
        earned += peopleInCoaster;
        // cerr << "id: " << id << ", peopleInCoaster: " << peopleInCoaster << endl;

        if (wasBefore[id].first) break;
        wasBefore[id].first = true;
        wasBefore[id].second.rideNr = C;
        wasBefore[id].second.peopleRides = earned;
    }

    if (C > 0)
    {
        int cycleSize = wasBefore[id].second.rideNr - C;
        int cycleCount = C / cycleSize;
        long long peopleInCycle = earned - wasBefore[id].second.peopleRides;
        C %= cycleSize;
        earned += peopleInCycle * cycleCount;

        while (C--)
        {
            int peopleInCoaster = 0;
            for (int i = 0; peopleInCoaster + group[(id + 1) % N] <= L && i < N; i++)
            {
                id = (id + 1) % N;
                peopleInCoaster += group[id];
            }
            earned += peopleInCoaster;
        }
    }

    cout << earned << endl;
}
