// https://www.codingame.com/training/easy/rocks-papers-scissors-es

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string moveToWin(const string& opponent) {
    switch (opponent[0]) {
    case 'R': return "Paper";
    case 'P': return "Scissors";
    default: return "Rock";
    }
}

int main()
{
    int n;
    cin >> n;

    vector<string> opponents(n);
    for (auto& opponent : opponents)
        cin >> opponent;

    int max_wins = 0;
    int best_position = 0;
    string best_move;
    for (int i = 0; i < n; i++) {
        int position = i;
        int games = 1;
        int wins = 1;
        auto my_move = moveToWin(opponents[position]);
        auto winning_opponent = moveToWin(my_move);
        for (position = (position + 1) % n; games < n; games++, position = (position + 1) % n) {
            if (opponents[position] == opponents[i]) wins++;
            else if (opponents[position] == winning_opponent) break;
        }
        if (wins > max_wins) {
            max_wins = wins;
            best_position = i;
            best_move = my_move;
        }
    }
    cout << best_move << endl << best_position << endl;
}
