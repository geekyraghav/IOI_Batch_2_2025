#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Trie {
public:
    vector<Trie*> children;
    bool isEnd;


    Trie() {
        children.resize(26, NULL);
        isEnd = false;
    }

    void insert(string s) {
        Trie* temp = this;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (temp->children[idx] == NULL) {
                temp->children[idx] = new Trie();
            }

            temp = temp->children[idx];
        }

        temp->isEnd = true;
    }

    bool search(string s) {
        Trie* temp = this;

        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';

            if (temp->children[idx] == NULL) {
                return false;
            }

            temp = temp->children[idx];
        }

        return temp->isEnd;
    }

};

int main() {
    Trie names;


    names.insert("kartik");
    names.insert("kashish");

    cout << names.search("kash") << endl;     // 0
    cout << names.search("kartik") << endl;   // 1
    cout << names.search("kashish") << endl;  // 1

}
