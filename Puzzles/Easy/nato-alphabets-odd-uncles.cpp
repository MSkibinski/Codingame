// https://www.codingame.com/training/easy/nato-alphabets-odd-uncles

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> year1908{ "Authority", "Bills", "Capture", "Destroy", "Englishmen", "Fractious", "Galloping", "High", "Invariably", "Juggling", "Knights", "Loose", "Managing", "Never", "Owners", "Play", "Queen", "Remarks", "Support", "The", "Unless", "Vindictive", "When", "Xpeditiously", "Your", "Zigzag" };
vector<string> year1917{ "Apples", "Butter", "Charlie", "Duff", "Edward", "Freddy", "George", "Harry", "Ink", "Johnnie", "King", "London", "Monkey", "Nuts", "Orange", "Pudding", "Queenie", "Robert", "Sugar", "Tommy", "Uncle", "Vinegar", "Willie", "Xerxes", "Yellow", "Zebra" };
vector<string> year1927{ "Amsterdam", "Baltimore", "Casablanca", "Denmark", "Edison", "Florida", "Gallipoli", "Havana", "Italia", "Jerusalem", "Kilogramme", "Liverpool", "Madagascar", "New-York", "Oslo", "Paris", "Quebec", "Roma", "Santiago", "Tripoli", "Uppsala", "Valencia", "Washington", "Xanthippe", "Yokohama", "Zurich" };
vector<string> year1956{ "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu" };
vector<vector<string>> alphabets = { year1908, year1917, year1927, year1956 };

int findAlphabetId(const string& word) {
    int id = 0;
    // search only through first 3 alphabets, if not present return 4th
    for (; id < alphabets.size() - 1; id++)
        if (binary_search(alphabets[id].begin(), alphabets[id].end(), word))
            break;
    return id;
}

int findNewVersionId(const vector<string>& words) {
    string prevWord;
    int newVersionId;
    for (auto& word : words) {
        if (word == "Charlie" || word == "Quebec") {
            if (prevWord.empty())
                prevWord = word;
            else if (prevWord != word) // we have Charlie and Quebec => year1956, new version id = 0
                return 0;
        }
        else
            return (findAlphabetId(word) + 1) % alphabets.size();
    }
}

int main()
{
    string word;
    vector<string> words;

    while (cin >> word)
        words.push_back(word);

    auto alphabet = alphabets[findNewVersionId(words)];

    string sep = "";
    for (auto& word : words)
        cout << sep << alphabet[word[0] - 'A'], sep = " ";
}
