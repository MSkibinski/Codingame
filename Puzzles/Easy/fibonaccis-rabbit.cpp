// https://www.codingame.com/training/easy/fibonaccis-rabbit

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int first_rabbits, years, min_age, max_age;
    cin >> first_rabbits >> years >> min_age >> max_age;

    vector<long long> newly_born(years + max_age + 1); // moving starting position by max_age value to simplify index operations
    int id = max_age;
    newly_born[id++] = first_rabbits;

    for (int i = 0, to_old_id = id - max_age - 1, young_enough_id = id - min_age; i < years; i++, id++, to_old_id++, young_enough_id++)
        newly_born[id] = (i == 0 ? 0 : newly_born[id - 1]) - newly_born[to_old_id] + newly_born[young_enough_id];

    cout << newly_born.back() << endl;
}
