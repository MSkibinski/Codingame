// https://www.codingame.com/training/medium/ascii-art-with-logo-language

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>

using namespace std;

class Logo {
    int minX = 100;
    int maxX = 100;
    int minY = 100;
    int maxY = 100;
    char symbol = '#';
    char space = ' ';
    vector<string> screen{ 200, string(200, ' ') };

    complex<int> pos{ 100, 100 };
    vector<complex<int>> dd{ {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
    int orientation = 0;

    bool pen_down = true;

    void clearscreen(char c) {
        space = c;
        screen = vector<string>{ 200, string(200, space) };
    }

    void move(int distance) {
        while (distance--) {
            if (pen_down)
                screen[pos.imag()][pos.real()] = symbol;
            pos += dd[orientation];
        }
        minX = min(minX, pos.real());
        maxX = max(maxX, pos.real());
        minY = min(minY, pos.imag());
        maxY = max(maxY, pos.imag());
    }

    void rotate(int angle) {
        // (x + 4) % 4 for left rotation (minus value) 
        orientation = (((orientation + angle / 90) % 4) + 4) % 4;
    }

public:
    void process(string full_command) {
        auto command = full_command.substr(0, full_command.find(' '));
        transform(command.begin(), command.end(), command.begin(), ::toupper);

        if (command == "CS")        clearscreen(full_command[3]);
        else if (command == "FD")   move(stoi(full_command.substr(3)));
        else if (command == "RT")   rotate(stoi(full_command.substr(3)));
        else if (command == "LT")   rotate(-1 * stoi(full_command.substr(3)));
        else if (command == "PU")   pen_down = false;
        else if (command == "PD")   pen_down = true;
        else if (command == "SETPC") symbol = full_command[6];
    }

    void print() {
        vector<string> result;
        for (int y = minY; y <= maxY; y++)
            result.push_back(screen[y].substr(minX, maxX - minX + 1));
        while (!result.empty() && result.back().find_first_not_of(space) == string::npos)
            result.erase(result.end());
        while (!result.empty() && result.front().find_first_not_of(space) == string::npos)
            result.erase(result.begin());

        auto spaces_at_front = result.front().find_first_not_of(space);
        for (int i = 1; i < result.size() && spaces_at_front; i++)
            spaces_at_front = min(spaces_at_front, result[i].find_first_not_of(space));

        for (auto line : result)
            if (auto pos = line.find_last_not_of(space); pos != string::npos)
                cout << line.substr(0, pos + 1).substr(spaces_at_front) << endl;
            else
                cout << endl;
    }

};

int main()
{
    int n;
    cin >> n; cin.ignore();

    Logo logo;
    while (n--) {
        string command;
        getline(cin, command);
        stringstream ss(command);
        while (getline(ss, command, ';'))
            logo.process(command);
    }

    logo.print();
}
