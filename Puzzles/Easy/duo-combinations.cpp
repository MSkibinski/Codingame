// https://www.codingame.com/training/easy/duo-combinations

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int total;
    cin >> total;;

    vector<string> symbols(total);
    for (auto& symbol : symbols)
        cin >> symbol;

    for (int i = 0; i < total - 1; i++) {
        for (int value = min(i, 1); value < (1 << total); value++) {
            for (int bit_n = total - 1; bit_n >= 0; bit_n--)
                cout << symbols[(value & 1 << bit_n) ? i + 1 : i];
            cout << endl;
        }
    }
}
