// https://www.codingame.com/training/medium/continued-fractions

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    string fraction;
    getline(cin, fraction);

    int p, q;
    vector<int> x;
    char separator;
    if (fraction[0] == '[') {
        stringstream ss(fraction.substr(1, fraction.size() - 2));
        do {
            int value;
            ss >> value;
            x.push_back(value);
        } while (ss >> separator);

        p = 1;
        q = 0;
        for (int i = x.size() - 1; i >= 0; i--) {
            swap(p, q);
            p += x[i] * q;
        }
        cout << p << "/" << q << endl;
    }
    else {
        stringstream ss(fraction);
        ss >> p >> separator >> q;

        x.push_back(floor(double(p) / q));
        p -= x.back() * q;
        while (p) {
            swap(p, q);
            x.push_back(p / q);
            p -= x.back() * q;
        }
        cout << "[" << x[0];
        separator = ';';
        for (int i = 1; i < x.size(); i++)
            cout << separator << " " << x[i], separator = ',';
        cout << "]" << endl;
    }
}
