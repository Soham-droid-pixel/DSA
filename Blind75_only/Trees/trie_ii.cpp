#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure for each node in the Trie
struct Node {
    Node* links[26];     // Links to child nodes (a-z)
    int cntEndWith = 0;  // How many words end EXACTLY at this node
    int cntPrefix = 0;   // How many words pass THROUGH this node (prefix count)

    // Helper: Check if a child node exists for a character
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    // Helper: Create a new child node
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Helper: Move to the child node
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Inserts a word and increments counts along the path
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->cntPrefix++; // This node is now part of one more word's prefix
        }
        node->cntEndWith++;    // One more word ends exactly here
    }

    // Returns exact frequency of the word
    int countWordsEqualTo(string word) {
        Node* node = root;
        for (char ch : word) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
            } else {
                return 0; // Word doesn't exist
            }
        }
        return node->cntEndWith;
    }

    // Returns how many words start with this prefix
    int countWordsStartingWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (node->containsKey(ch)) {
                node = node->get(ch);
            } else {
                return 0; // Prefix doesn't exist
            }
        }
        return node->cntPrefix;
    }

    // Deletes one occurrence of a word
    void erase(string word) {
        Node* node = root;
        // We assume the word exists based on problem constraints
        for (char ch : word) {
            node = node->get(ch);
            node->cntPrefix--; // Decrease prefix count as we pass through
        }
        node->cntEndWith--;    // Decrease the end count at the final node
    }
};

int main() {
    Trie trie;
    
    trie.insert("apple");
    trie.insert("apple");
    trie.insert("apps");

    cout << "Words equal to 'apple': " << trie.countWordsEqualTo("apple") << endl; // 2
    cout << "Words starting with 'app': " << trie.countWordsStartingWith("app") << endl; // 3

    trie.erase("apple");
    cout << "Words equal to 'apple' after erase: " << trie.countWordsEqualTo("apple") << endl; // 1
    cout << "Words starting with 'app' after erase: " << trie.countWordsStartingWith("app") << endl; // 2

    return 0;
}