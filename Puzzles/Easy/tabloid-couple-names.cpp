// https://www.codingame.com/training/easy/tabloid-couple-names

#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Smoosher {
public:
    Smoosher(string n1, string n2) : name1(n1), name2(n2) {
        for (auto& c : name1) c = tolower(c);
        for (auto& c : name2) c = tolower(c);
    }

    set<string> operator()() {
        smoosh(name1, name2);
        smoosh(name2, name1);

        if (results.empty())
            results.insert("NONE");

        return results;
    }

private:
    string name1;
    string name2;

    int overlapping = 1;
    set<string> results;

    void smoosh(string n1, string n2) {
        for (auto pos1 = 0; pos1 <= n1.size() - overlapping; pos1++) {
            auto pos2 = n2.find(n1.substr(pos1, overlapping), 1);
            while (pos2 != string::npos) {
                int curr_overlapping = overlapping;
                while (pos2 + curr_overlapping < n2.size() && n2[pos2 + curr_overlapping] == n1[pos1 + curr_overlapping])
                    curr_overlapping++;

                string result = n2.substr(0, pos2) + n1.substr(pos1);
                if (result.size() >= min(n1.size(), n2.size())
                    && result != name1.substr(0, result.size())
                    && result != name2.substr(0, result.size())) {
                    if (curr_overlapping > overlapping) {
                        overlapping = curr_overlapping;
                        results.clear();
                    }
                    results.insert(result);
                }
                pos2 = n2.find(n1.substr(pos1, overlapping), pos2 + 1);
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;

    while (n--) {
        string name1, name2, sep;
        cin >> name1 >> sep >> name2; cin.ignore(256, '\n');

        auto results = Smoosher(name1, name2)();

        cout << name1 << " plus " << name2 << " = ";
        sep = "";
        for (auto result : results) {
            result[0] = toupper(result[0]);
            cout << sep << result, sep = " ";
        }
        cout << endl;
    }
}
