// https://www.codingame.com/training/medium/fix-the-spaces

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

class Solver {
    string sentence;
    int position = 0;
    list<string> result;
    list<string> final_result;
    bool result_found = false;

    map<string, int> words;

public:
    void read() {
        cin >> sentence;
        for (string word; cin >> word;)
            words[word]++;
    }

    void solve() {
        for (auto it = lower_bound(words.begin(), words.end(), sentence.substr(position, 1),
                    [](auto& word, auto& letter) {return word.first < letter; });
                it != words.end() && it->first <= sentence.substr(position, it->first.size());
                it++) {
            if (it->second && it->first == sentence.substr(position, it->first.size())) {
                it->second--;
                position += it->first.size();
                result.push_back(it->first);
                if (position == sentence.size()) {
                    if (result_found) {
                        cout << "Unsolvable" << endl;
                        exit(0);
                    }
                    final_result = result;
                    result_found = true;;
                }
                else
                    solve();

                result.pop_back();
                position -= it->first.size();
                it->second++;
            }
        }
    }
    void print_result() {
        string sep = "";
        for (auto& word : final_result)
            cout << sep << word, sep = " ";
        cout << endl;
    }
};

int main()
{
    Solver solver;

    solver.read();
    solver.solve();
    solver.print_result();
}