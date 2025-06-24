// https://www.codingame.com/training/easy/digital-scoreboard

#include <iostream>
#include <string>

using namespace std;

class Scoreboard {
public:
    Scoreboard(const string& s) : data(s) {}

    void modifyWith(const string& s, char c) {
        for (int i = 0; i < data.size(); i++)
            if (s[i] != ' ')
                data[i] = c;
    }

    string getScore() {
        return getDigit(0) + getDigit(1);
    }

private:
    string data;

    //   aaaa
    //   b  c
    //   dddd
    //   e  f
    //   gggg
    string getDigit(int id) {
        int shift = id * 8;
        if (a(shift) && b(shift) && c(shift) && !d(shift) && e(shift) && f(shift) && g(shift)) return "0";
        if (!a(shift) && !b(shift) && c(shift) && !d(shift) && !e(shift) && f(shift) && !g(shift)) return "1";
        if (a(shift) && !b(shift) && c(shift) && d(shift) && e(shift) && !f(shift) && g(shift)) return "2";
        if (a(shift) && !b(shift) && c(shift) && d(shift) && !e(shift) && f(shift) && g(shift)) return "3";
        if (!a(shift) && b(shift) && c(shift) && d(shift) && !e(shift) && f(shift) && !g(shift)) return "4";
        if (a(shift) && b(shift) && !c(shift) && d(shift) && !e(shift) && f(shift) && g(shift)) return "5";
        if (a(shift) && b(shift) && !c(shift) && d(shift) && e(shift) && f(shift) && g(shift)) return "6";
        if (a(shift) && !b(shift) && c(shift) && !d(shift) && !e(shift) && f(shift) && !g(shift)) return "7";
        if (a(shift) && b(shift) && c(shift) && d(shift) && e(shift) && f(shift) && g(shift)) return "8";
        return "9";
    }

    bool a(int shift) { return data[20 + shift] != ' '; }
    bool b(int shift) { return data[36 + shift] != ' '; }
    bool c(int shift) { return data[40 + shift] != ' '; }
    bool d(int shift) { return data[54 + shift] != ' '; }
    bool e(int shift) { return data[70 + shift] != ' '; }
    bool f(int shift) { return data[74 + shift] != ' '; }
    bool g(int shift) { return data[88 + shift] != ' '; }
};

string read7lines() {
    string result;
    for (int i = 0; i < 7; i++) {
        string row;
        getline(cin, row);
        result += row;
    }
    return result;
}

int main()
{
    Scoreboard scoreboard(read7lines());

    string row;
    getline(cin, row);
    scoreboard.modifyWith(read7lines(), ' ');

    getline(cin, row);
    scoreboard.modifyWith(read7lines(), 'x');

    cout << scoreboard.getScore() << endl;
}
