// https://www.codingame.com/training/easy/card-counting-when-easily-distracted

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
    string stream_of_consciousness;
    getline(cin, stream_of_consciousness);

    // 0 - not_used
    // 1 - A
    // 2-9 - cards 2-9
    // 10 - KQJT
    vector<int> remaining_cards(11, 4);
    remaining_cards[0] = 0;
    remaining_cards[10] = 4 * 4;
    int remains = 52;

    istringstream ss(stream_of_consciousness);
    for (string s; getline(ss, s, '.');) {
        if (s.find_first_not_of("23456789KQJTA") != string::npos) continue;
        for (auto c : s)
            if (isdigit(c))
                remaining_cards[c - '0']--;
            else
                remaining_cards[c == 'A' ? 1 : 10]--;
        remains -= s.size();
    }

    int bust_threshold;
    cin >> bust_threshold;

    int possible_cards = accumulate(&remaining_cards[1], &remaining_cards[bust_threshold], 0);
    cout << round(possible_cards * 100.0 / remains) << "%" << endl;
}
