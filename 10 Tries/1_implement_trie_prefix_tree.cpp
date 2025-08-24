/*
    https://leetcode.com/problems/implement-trie-prefix-tree/

    A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

    Implement the Trie class:
        - Trie() Initializes the trie object.
        - void insert(String word) Inserts the string word into the trie.
        - boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
        - boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

    Input
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    Output
    [null, null, true, false, true, null, true]
*/

#include<bits/stdc++.h>
using namespace std;

typedef struct Node {
    struct Node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
} Node;

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;

        for(int i = 0; i < word.length(); i++) {
            // if node doesn't have this key
            if(!node->containsKey(word[i])) {
                // create the new node of that key
                node->put(word[i], new Node());
            }

            // move to next node
            node = node->get(word[i]);
        }

        // mark the end of the word
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;

        for(int i = 0; i < word.length(); i++) {
            // if a character is not found
            if(!node->containsKey(word[i])) return false;
            
            // move to next character
            node = node->get(word[i]);
        }

        // check if the last node is an ending of word or not
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node *node = root;

        for(int i = 0; i < prefix.length(); i++) {
            // if a character is not found
            if(!node->containsKey(prefix[i])) return false;
            
            // move to next character
            node = node->get(prefix[i]);
        }

        return true;
    }
};

int main() {
    Trie trie;

    cout << "Inserting words: apple, apps, apxl, bac, bat" << endl;
    trie.insert("apple");
    trie.insert("apps");
    trie.insert("apxl");
    trie.insert("bac");
    trie.insert("bat");

    cout << "Search if apple exists in trie: " << (trie.search("apple") ? "True" : "False")<< endl;
    cout << "Search if appl exists in trie: " << (trie.search("appl") ? "True" : "False")<< endl;

    cout << "If words is Trie start with app: " << (trie.startsWith("app") ? "True" : "False" )<< endl;
    cout << "If words is Trie start with appx: " << (trie.startsWith("appx") ? "True" : "False" )<< endl;

    return 0;
}