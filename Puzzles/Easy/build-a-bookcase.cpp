// https://www.codingame.com/training/easy/build-a-bookcase

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int height, width, number_of_shelves;
    cin >> height >> width >> number_of_shelves;

    const string sides = '|' + string(width - 2, ' ') + '|';
    const string bottom = '|' + string(width - 2, '_') + '|';
    const int big_shelves = (height - 1) % number_of_shelves;
    const int shelf_height = (height - 1) / number_of_shelves;

    auto construct_shelf = [&](int h) {
        while (--h)
            cout << sides << endl;
        cout << bottom << endl;
    };

    cout << string(width / 2, '/') << string(width % 2, '^') << string(width / 2, '\\') << endl;
    for (int i = 0; i < number_of_shelves - big_shelves; i++)
        construct_shelf(shelf_height);
    for (int i = 0; i < big_shelves; i++)
        construct_shelf(shelf_height + 1);
}
