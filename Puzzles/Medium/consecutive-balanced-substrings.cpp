// https://www.codingame.com/training/medium/consecutive-balanced-substrings

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<bool> achieved(n + 1);
    int remainingZeros = count(s.begin(), s.end(), '0');
    int remainingOnes = n - remainingZeros;
    int longestCBS = 0;

    for (int i = 0; i<n && min(remainingZeros, remainingOnes)>longestCBS; i++) {
        if (achieved[i])
            continue;
        int stackValue = 0;
        int currentCBS = 0;
        for (int j = i; j < n; j++) {
            stackValue += s[j] == '1' ? 1 : -1;
            if (stackValue == 0) {
                currentCBS++;
                achieved[j + 1] = true;
            }
        }
        longestCBS = max(longestCBS, currentCBS);
        s[i] == '0' ? remainingZeros-- : remainingOnes--;
    }

    cout << longestCBS << endl;
}
