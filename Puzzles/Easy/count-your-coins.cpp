// https://www.codingame.com/training/easy/count-your-coins

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int value_to_reach, n;
    cin >> value_to_reach >> n;

    vector<pair<uint, uint>> coins(n);
    for (auto& coin : coins) cin >> coin.second;
    for (auto& coin : coins) cin >> coin.first;

    sort(coins.begin(), coins.end());

    int coins_needed = 0;
    for (auto& coin : coins) {
        if (coin.first * coin.second >= value_to_reach) {
            coins_needed += (value_to_reach + coin.first - 1) / coin.first;
            value_to_reach = 0;
            break;
        }
        coins_needed += coin.second;
        value_to_reach -= coin.first * coin.second;
    }

    cout << (value_to_reach ? -1 : coins_needed) << endl;
}
