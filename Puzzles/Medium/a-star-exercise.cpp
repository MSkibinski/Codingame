// https://www.codingame.com/training/medium/a-star-exercise

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

struct Node {
    int g, h;
    vector<pair<int, int>> neighbours; // id + distance
};

int main()
{
    int n, e, startId, endId;
    cin >> n >> e >> startId >> endId;

    vector<Node> nodes(n);
    for (auto& node : nodes)
        cin >> node.h;

    for (int i = 0; i < e; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        nodes[x].neighbours.push_back({ y, c });
        nodes[y].neighbours.push_back({ x, c });
    }

    priority_queue<Pair, vector<Pair>, greater<Pair>> openList;
    openList.push({ nodes[startId].h, startId });
    vector<bool> closedList(n);

    while (true) {
        auto [f, id] = openList.top();
        openList.pop();
        if (closedList[id])
            continue;
        closedList[id] = true;

        cout << id << " " << f << endl;
        if (id == endId)
            break;
        for (auto [neighbourId, distance] : nodes[id].neighbours)
            if (!closedList[neighbourId]) {
                openList.push({ nodes[id].g + distance + nodes[neighbourId].h, neighbourId });
                nodes[neighbourId].g = nodes[neighbourId].g ? min(nodes[id].g + distance, nodes[neighbourId].g) : nodes[id].g + distance;
            }
    }
}
