#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

int findMaxDifLetters(const string &filename) {
    ifstream file(filename);
    string word;
    vector<string> result;
    int maxdif = 0;
    if (!file.is_open()) {
        cout << "Error, file isn't found" << endl;
    } else {
        while (file >> word) {
            unordered_set<char> set;
            for (char ch: word) {
                set.insert(ch);
            }
            if (maxdif < set.size()) {
                maxdif = set.size();
                result.clear();
            }
            if (set.size() == maxdif) {
                result.push_back(word);
            }
        }
    }
    file.close();
    cout << "The greatest number of different letters: " << maxdif << endl;
    cout << "There are " << result.size() << " words that has the greatest number of different letters: " << endl;
    for (int i = 0; i < result.size(); i++) {
        if (i % 4 == 0 and i != 0) {
            cout << result[i] << " ; " << endl;
        } else {
            cout << result[i] << " ; ";
        }
    }
    cout << endl;
    return 0;
}


int main() {
    cout << "Test #1 " << endl;
    findMaxDifLetters("test1.txt");
    cout << "Test #2" << endl;
    findMaxDifLetters("test2.txt");
    return 0;
}
