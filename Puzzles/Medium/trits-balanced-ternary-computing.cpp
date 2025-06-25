// https://www.codingame.com/training/medium/trits-balanced-ternary-computing

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int toDecimal(const string& s) {
    int value = 0;
    for (int i = s.size() - 1, k = 1; i >= 0; i--, k *= 3)
        value += (s[i] == '1' ? k : (s[i] == '0' ? 0 : -k));
    return value;
}

string toTernary(int N) {
    const char* letters = N < 0 ? "0T1" : "01T";
    if (N < 0) N = -N;

    string result;
    do {
        result += letters[N % 3];
        N = (N + 1) / 3;
    } while (N);

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string left, op, right;
    cin >> left >> op >> right;

    int leftValue = toDecimal(left);
    int rightValue = toDecimal(right);
    string result;
    switch (op[0]) {
    case '+': result = toTernary(leftValue + rightValue); break;
    case '-': result = toTernary(leftValue - rightValue); break;
    case '>': result = (rightValue >= left.size() ? "0" : left.substr(0, left.size() - rightValue)); break;
    case '<': result = left + string(rightValue, '0'); break;
    case '*': result = toTernary(leftValue * rightValue); break;
    }
    cout << result << endl;
}
