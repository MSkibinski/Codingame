// https://www.codingame.com/training/easy/the-helpdesk

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Counter {
    float efficiency = 0;
    int visitors = 0;
    int breaks = 0;
    float total_time = 0;
    float time_from_break = 0;
};

class Company {
    int worktime;
    vector<Counter> counters;

public:
    void init() {
        cin >> worktime;

        int nc;
        cin >> nc;
        counters.resize(nc);
        for (auto& c : counters)
            cin >> c.efficiency;
    }

    void handle_visitor() {
        float helptime;
        cin >> helptime;

        while (true) {
            auto first_available = min_element(counters.begin(), counters.end(),
                [&](const auto& e1, const auto& e2) {
                    if (e1.total_time == e2.total_time && (e1.time_from_break >= worktime || e2.time_from_break >= worktime)) {
                        return e1.time_from_break < e2.time_from_break;
                    }
                    return e1.total_time < e2.total_time;
                });
            if (first_available->time_from_break >= worktime) {
                first_available->time_from_break = 0;
                first_available->total_time += 10;
                first_available->breaks++;
            }
            else {
                first_available->visitors++;
                float visitor_time = helptime / first_available->efficiency;
                first_available->time_from_break += visitor_time;
                first_available->total_time += visitor_time;
                break;
            }
        }
    }

    void print_summary() {
        string sep = "";
        for (const auto& counter : counters)
            cout << sep << counter.visitors, sep = " ";
        cout << endl;

        sep = "";
        for (const auto& counter : counters)
            cout << sep << counter.breaks, sep = " ";
        cout << endl;
    }
};

int main()
{
    Company HAB;
    HAB.init();

    int nv;
    cin >> nv;
    while (nv--)
        HAB.handle_visitor();

    HAB.print_summary();
}
