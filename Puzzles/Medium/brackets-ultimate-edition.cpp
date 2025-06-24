// https://www.codingame.com/training/medium/brackets-ultimate-edition

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

char absBracket(char c) {
    switch (c) {
    case '(': case ')': return '(';
    case '<': case '>': return '<';
    case '{': case '}': return '{';
    default: return '[';
    }
}

bool isBracket(unsigned char c) {
    return string("()[]{}<>").find(c) != string::npos;
}
bool isOpenBracket(char c) {
    return c == '(' || c == '[' || c == '{' || c == '<';
}

int findMinimalFlipping(const string& s) {
    if (s.empty()) return 0;

    stack<char> st;
    int result = numeric_limits<int>::max();
    for (int i = 0; i < s.size(); i++) {
        char last = st.empty() ? 0 : st.top();
        absBracket(s[i]) == last ? st.pop() : st.push(absBracket(s[i]));
        if (st.empty()) {
            // when stack is empty we can split our expression into two parts: ")[..]){..}" = flips for "))" + [..] + {..}
            int flips = (isOpenBracket(s[0]) ? 0 : 1) + (!isOpenBracket(s[i]) ? 0 : 1) + findMinimalFlipping(s.substr(1, i - 1)) + findMinimalFlipping(s.substr(i + 1));

            result = min(result, flips);

            // instead of closing every possible matching bracket we should also consider this bracket as new opening bracket
            // so we need add this brackets to stack
            // this is for cases like: (<<<<)(>>>>)
            st.push(absBracket(s[i]));
            st.push(absBracket(s[i]));
        }
    }
    return result;
}

bool isValid(const string& expression) {
    stack<char> s;
    for (auto c : expression) {
        char last = s.empty() ? 0 : s.top();
        last == absBracket(c) ? s.pop() : s.push(absBracket(c));
    }
    return s.empty();
}

int main()
{
    int N;
    cin >> N; cin.ignore();

    for (int i = 0; i < N; i++) {
        string expression;
        getline(cin, expression);
        expression.erase(std::remove_if(expression.begin(), expression.end(), [](auto c) {return !isBracket(c); }),
            expression.end());

        cout << (isValid(expression) ? findMinimalFlipping(expression) : -1) << endl;
    }
}
