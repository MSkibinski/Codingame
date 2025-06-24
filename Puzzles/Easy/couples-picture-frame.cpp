// https://www.codingame.com/training/easy/couples-picture-frame

#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    string wife, husband;
    cin >> wife >> husband;

    int width = lcm(wife.size(), husband.size());

    auto printHorizontal = [width](string& name) {
        for (int i = 0; i < width / name.size(); i++)
            cout << name;
        cout << endl;
        };

    printHorizontal(wife);

    for (int i = 0; i < width; i++)
        cout << husband[i % husband.size()] << string(width - 2, ' ') << wife[i % wife.size()] << endl;

    printHorizontal(husband);
}
