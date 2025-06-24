// https://www.codingame.com/training/easy/crazy-list

#include <iostream>

using namespace std;

/*
    difference between consecutive elements alwasy increase by the same factor
    a1 a2 a3 a4
    a3-a2 = (a2-a1) * M
    a4-a3 = (a3-a2) * M
*/

int main()
{
    int a1, a2;
    cin >> a1 >> a2;
    int first_diff = a2 - a1;
    if (first_diff == 0) {
        cout << a2 << endl;
        return 0;
    }

    int a3;
    cin >> a3;
    int last_diff = a3 - a2;
    int factor = first_diff ? last_diff / first_diff : 0;

    while (cin >> a2) {
        last_diff = a2 - a3;
        a3 = a2;
    }

    cout << a3 + last_diff * factor << endl;
}
