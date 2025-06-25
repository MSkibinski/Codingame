// https://www.codingame.com/training/medium/sticky-keyboard

#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

bool isDuplication(const string& w1, const string& w2) {
    int duplications = 0;
    for (int i = 0, j = 0; i < w1.size() && j < w2.size(); i++, j++) {
        if (w1[i] != w2[j]) {
            if (i > 0) i--;
            duplications++;
            if (w1[i] != w2[j] || duplications > 1)
                return false;
        }
    }
    return duplications == 0 ? w1.back() == w2.back() : true;
}
bool isCharacterMissing(const string& w1, const string& w2) {
    int missing = 0;
    for (int i = 0, j = 0; i < w1.size() && j < w2.size(); i++, j++) {
        if (w1[i] != w2[j]) {
            i++;
            missing++;
            if (missing > 1 || w1[i] != w2[j])
                return false;
        }
    }
    return true;
}

bool areSimilar(const string& w1, const string& w2) {
    if (w1.size() + 1 == w2.size())
        return isDuplication(w1, w2);
    else if (w1.size() - 1 == w2.size())
        return isCharacterMissing(w1, w2);
    return false;
}

int main()
{
    int n;
    cin >> n; cin.ignore();

    string text;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        text += line + '\n';
    }

    unordered_map<string, int> words;
    regex rgx("\\w+");
    for (sregex_iterator it(text.begin(), text.end(), rgx), it_end; it != it_end; it++)
        words[(*it)[0]]++;

    vector<pair<string, int>> v(words.begin(), words.end());
    sort(v.begin(), v.end(), [](auto& p1, auto& p2) {
        return p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first;
        });

    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            if (v[i].second > v[j].second && areSimilar(v[i].first, v[j].first))
                text = regex_replace(text, regex("\\b" + v[j].first + "\\b"), v[i].first);

    cout << text;
}
