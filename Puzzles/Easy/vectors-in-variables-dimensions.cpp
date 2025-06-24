// https://www.codingame.com/training/easy/vectors-in-variables-dimensions

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Point {
    string name;
    vector<int> v;

    void create(const string& data, int d) {
        stringstream ss(data);
        getline(ss, name, '(');

        v.resize(d);
        for (int i = 0; i < d; i++) {
            char sep;
            ss >> v[i] >> sep;
        }
    }

    int distance(const Point& p2) {
        int result = 0;
        for (int i = 0; i < v.size(); i++)
            result += (v[i] - p2.v[i]) * (v[i] - p2.v[i]);
        return result;
    }
};

void printVector(const Point& p1, const Point& p2) {
    cout << p1.name << p2.name << "(";
    string sep = "";
    for (int i = 0; i < p1.v.size(); i++)
        cout << sep << p2.v[i] - p1.v[i], sep = ",";
    cout << ")" << endl;
}

int main()
{
    int d, n;
    cin >> d >> n; cin.ignore();

    vector<Point> points(n);

    for (auto& point : points) {
        string line;
        getline(cin, line);
        point.create(line, d);
    }

    int shortest = numeric_limits<int>::max();
    int longest = -1;
    int shortestStartId, shortestEndId;
    int longestStartId, longestEndId;

    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = points[i].distance(points[j]);
            if (dist < shortest) {
                shortest = dist;
                shortestStartId = i;
                shortestEndId = j;
            }
            if (dist > longest) {
                longest = dist;
                longestStartId = i;
                longestEndId = j;
            }
        }
    }

    printVector(points[shortestStartId], points[shortestEndId]);
    printVector(points[longestStartId], points[longestEndId]);
}
