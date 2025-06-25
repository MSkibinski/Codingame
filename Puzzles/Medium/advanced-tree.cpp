// https://www.codingame.com/training/medium/advanced-tree

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <complex>

using namespace std;

bool showHidden = false;
bool onlyDirectories = false;
int maxDepth = 666;

void parseFlags(string& flags) {
    istringstream ss(flags);
    string f;
    while (getline(ss, f, ',')) {
        if (f.find("-a") != string::npos)
            showHidden = true;
        else if (f.find("-d") != string::npos)
            onlyDirectories = true;
        else if (f.find("-L") != string::npos && f.size() > 2)
            maxDepth = stoi(f.substr(2));
    }
}

class Node {
    string name;
    map<string, Node> children;
    bool isDir = true;

    string createKey(string key) {
        if (key[0] == '.')
            key.erase(0, 1);
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        return key;
    }

public:
    void addFile(const string& fileName) {
        if (auto pos = fileName.find('/'); pos != string::npos) {
            auto& child = children[createKey(fileName.substr(0, pos))];
            child.addFile(fileName.substr(pos + 1));
            if (child.name.empty())
                child.name = fileName.substr(0, pos);
        }
        else if (!onlyDirectories) {
            auto& file = children[createKey(fileName)];
            file.name = fileName;
            file.isDir = false;
        }
    }

    complex<int> printAll(const string& prefix = "", int curentDepth = 0) {
        complex<int> result{ isDir, !isDir };

        if (curentDepth < maxDepth) {
            int n = children.size();
            int i = 0;
            for (auto& [key, child] : children) {
                cout << prefix << (++i == n ? "`-- " : "|-- ") << child.name << endl;
                result += child.printAll(prefix + (i == n ? "    " : "|   "), curentDepth + 1);
            }
        }

        return result;
    }
};

int main()
{
    string s, f;
    getline(cin, s);
    getline(cin, f);
    string s2 = (s[0] != '.' ? "./" : "") + s + "/";

    int n;
    cin >> n;
    map<string, Node> tree;

    parseFlags(f);

    while (n--) {
        string fileName;
        cin >> fileName;

        if (fileName.compare(0, s2.size(), s2) != 0) continue;
        fileName = fileName.substr(s2.size() - 1);

        if (!showHidden && fileName.find("/.") != string::npos) continue;

        tree[s2].addFile(fileName.substr(1));
    }

    complex<int> result{ 1, 0 };
    if (tree.empty())
        cout << s << " [error opening dir]" << endl;
    else {
        cout << s << endl;
        result = tree[s2].printAll();
    }

    cout << endl;
    cout << result.real() - 1 << " director" << (result.real() == 2 ? "y" : "ies");
    if (!onlyDirectories)
        cout << ", " << result.imag() << " " << (result.imag() == 1 ? "file" : "files") << endl;

}
