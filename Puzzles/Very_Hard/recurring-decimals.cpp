// https://www.codingame.com/training/expert/recurring-decimals

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<long long, unsigned> history;
    string result;
    long long value = 1;
    for (unsigned i = 0; value && !history.contains(value); i++) {
        history[value] = i;

        value *= 10;
        int digit = value / n;
        result += '0' + digit;
        value %= n;
    }

    if (value) {
        auto start_of_recursion = history[value];
        cout << "0." << result.substr(0, start_of_recursion) << "(" << result.substr(start_of_recursion) << ")" << endl;
    }
    else {
        cout << "0." << result << endl;
    }
}
