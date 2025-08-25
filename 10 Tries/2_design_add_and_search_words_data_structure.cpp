/*
    Design a data structure that supports adding new words and finding if a string matches any previously added string.

    Implement the WordDictionary class:

        - WordDictionary() Initializes the object.
        - void addWord(word) Adds word to the data structure, it can be matched later.
        - bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

    Input
        ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
        [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
    Output
        [null,null,null,null,false,true,true,true]
*/

typedef struct Node {
    struct Node *arr[26];
    bool flag = false;

    bool containsKey(char ch) {
        return arr[ch - 'a'] != NULL;
    }

    void set(char ch, Node *node) {
        arr[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return arr[ch - 'a'];
    }

    void markEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
}Node;

class WordDictionary {
private:
    Node *root;

    bool searchHelper(string &word, Node *node, int idx) {
        if(idx == word.length()) {
            return node->isEnd();
        }

        // if current character is not dot '.'
        if(word[idx] != '.') {
            // if next link is not present
            if(!node->containsKey(word[idx]))   return false;

            // check for next link
            return searchHelper(word, node->get(word[idx]), idx+1);
        }

        // current character is dot '.'
        // check for all valid combinations

        for(int i = 0; i < 26; i++) {
            // if there is a link for a character
            if(node->containsKey('a' + i)) {
                // check for next letters by skipping that 
                if(searchHelper(word, node->get('a' + i), idx+1))   return true;
            } 
        }

        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(int i = 0; i < word.length(); i++) {
            // if no next link
            if(!node->containsKey(word[i])) {
                // create next link
                node->set(word[i], new Node());
            }
            
            // go to next link
            node = node->get(word[i]);
        }

        // mark end of word
        node->markEnd();
    }
    
    bool search(string word) {
        return searchHelper(word, root, 0);
    }
};