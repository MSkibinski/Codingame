// https://www.codingame.com/training/medium/find-the-missing-plus-signs-in-addition

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> digits;
vector<vector<long long>> products;
vector<long long> solution;

int terms;
long long sum;
int solutions = 0;

void printSolution() {
    solutions++;
    string separator = "";
    for (auto term : solution)
        cout << separator << term, separator = "+";
    cout << "=" << sum << endl;
}

void findSolutions(int digitsStartId, int terms_remaining, long long sum_remaining) {
    if (terms_remaining == 1) {
        if (sum_remaining == products[digitsStartId].back()) {
            solution[terms - terms_remaining] = sum_remaining;
            printSolution();
        }
        return;
    }

    for (int digitsEndId = digitsStartId; digitsEndId + terms_remaining <= digits.size(); digitsEndId++) {
        auto value = products[digitsStartId][digitsEndId];
        if (value >= sum_remaining)
            return;
        solution[terms - terms_remaining] = value;
        findSolutions(digitsEndId + 1, terms_remaining - 1, sum_remaining - value);
    }
}

int main()
{
    string o;
    cin >> terms >> sum >> o;

    digits.reserve(o.size());
    for (auto c : o)
        digits.push_back(c - '0');

    // product[i][j] = number created by concatenation digits from index i to j
    products.resize(digits.size(), vector<long long>(digits.size()));
    for (int i = 0; i < digits.size(); i++) {
        long long value = 0;
        for (int j = i; j < digits.size(); j++) {
            value = value * 10 + digits[j];
            products[i][j] = value;
            if (value >= sum) break;
        }
    }

    solution.resize(terms);
    findSolutions(0, terms, sum);

    if (!solutions)
        cout << "No solution" << endl;
}
