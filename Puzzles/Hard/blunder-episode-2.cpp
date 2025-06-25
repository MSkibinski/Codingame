// https://www.codingame.com/training/hard/blunder-episode-2

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Room
{
public:
    void fill(int money, int child1Id, int child2Id)
    {
        value = money;
        totalValue = money;
        child1 = child1Id;
        child2 = child2Id;
    }

    void addParent(int parent)
    {
        parents.push_back(parent);
    }

    int child1, child2;
    vector<int> parents;
    int value, totalValue;
};

int main()
{
    int N;
    cin >> N; cin.ignore();
    vector<Room> rooms(N);
    queue<int> endings;
    for (int i = 0; i < N; i++) {
        int id, money, child1Id, child2Id;
        string child1, child2;
        cin >> id >> money >> child1 >> child2;

        child1Id = (child1[0] == 'E' ? -1 : stoi(child1));
        child2Id = (child2[0] == 'E' ? -1 : stoi(child2));
        rooms[id].fill(money, child1Id, child2Id);

        if (child1Id != -1) rooms[child1Id].addParent(id);
        if (child2Id != -1) rooms[child2Id].addParent(id);

        if (child1Id + child2Id == -2)
        {
            endings.push(id);
        }
    }

    while (!endings.empty())
    {
        int id = endings.front();
        endings.pop();

        for (auto parentId : rooms[id].parents)
        {
            auto& room = rooms[parentId];
            if (rooms[id].totalValue + room.value > room.totalValue)
                room.totalValue = rooms[id].totalValue + room.value;

            if (room.child1 == id)
                room.child1 = -1;
            else
                room.child2 = -1;

            if (room.child1 + room.child2 == -2)
            {
                endings.push(parentId);
            }
        }
    }

    cout << rooms[0].totalValue << endl;
}
