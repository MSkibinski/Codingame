// https://www.codingame.com/training/medium/frog-exchange

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, string>> rules{
    {"m s f f", "m f s f"},
    {"m s f m", "s m f m"},
    {"m s f", "m f s"},
    {"m f s", "s f m"},
    {"s m f", "f m s"},
    {"f m s", "f s m"},
    {"s f m", "f s m"} };

int main()
{
    string a;
    getline(cin, a);
    cout << a << endl;

    bool reversed = false;
    if (a[0] == 'f') {
        reversed = true;
        reverse(a.begin(), a.end());
    }


    for (bool patternFound = true; patternFound; ) {
        patternFound = false;
        for (auto& [pattern, changeInto] : rules)
            if (auto pos = a.find(pattern); pos != string::npos) {
                a.replace(pos, pattern.size(), changeInto);
                auto result = a;
                if (reversed)
                    reverse(result.begin(), result.end());
                cout << result << endl;
                patternFound = true;
                break;
            }
    }
}
