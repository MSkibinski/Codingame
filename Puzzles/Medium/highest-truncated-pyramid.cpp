// https://www.codingame.com/training/medium/highest-truncated-pyramid

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int first = 1;
    int last = 2;
    int sum = 1;
    while (sum != n)
        if (sum < n)
            sum += last++;
        else
            sum -= first++;

    while (first < last)
        cout << string(first++, '*') << endl;
}
