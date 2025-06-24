// https://www.codingame.com/training/easy/you-are-the-father-maury-povich-style

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_chromosomes_pairs() {
    string line, s;
    getline(cin, line);
    stringstream ss(line);
    ss >> s >> s;

    vector<string> chromosomes_pairs;
    while (ss >> s)
        chromosomes_pairs.push_back(s);

    return chromosomes_pairs;
}

bool pairPossible(const string& m, const string& f, const string& ch) {
    if (m[0] == ch[0] || m[1] == ch[0])
        if (f[0] == ch[1] || f[1] == ch[1])
            return true;
    if (m[0] == ch[1] || m[1] == ch[1])
        if (f[0] == ch[0] || f[1] == ch[0])
            return true;
    return false;
}

int main()
{
    vector<string> mother_chromosomes_pairs = get_chromosomes_pairs();
    vector<string> child_chromosomes_pairs = get_chromosomes_pairs();

    int num;
    cin >> num; cin.ignore();
    while (num--) {
        string line, name, father_chromosomes_pair;
        getline(cin, line);
        stringstream ss(line);

        ss >> name;
        bool possible_father = true;
        for (int i = 0; i < mother_chromosomes_pairs.size(); i++) {
            ss >> father_chromosomes_pair;
            if (!pairPossible(mother_chromosomes_pairs[i], father_chromosomes_pair, child_chromosomes_pairs[i])) {
                possible_father = false;
                break;
            }
        }

        if (possible_father) {
            cout << name.substr(0, name.size() - 1) << ", you are the father!" << endl;
            break;
        }
    }
}
