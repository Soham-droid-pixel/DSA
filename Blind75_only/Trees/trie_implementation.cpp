#include <iostream>   // For input and output operations
#include <string>     // For using the string data type
#include <vector>     // For dynamic array capabilities (optional here)

using namespace std;  // Allows using standard library names without std:: prefix

// Class representing a single node in the Trie
class TrieNode {
public:
    TrieNode* children[26];   // Array of pointers to children nodes, one for each letter a-z
    bool isEndOfWord;         // Boolean flag to mark if a complete word ends at this node

    TrieNode() {              // Constructor for initializing a new node
        isEndOfWord = false;  // By default, a new node does not mark the end of a word
        for (int i = 0; i < 26; i++) { // Loop through all 26 possible child pointers
            children[i] = nullptr;     // Set each child pointer to null initially
        }
    }
};

// Main Trie class to handle insert, search, and prefix operations
class Trie {
private:
    TrieNode* root;           // Private pointer to the root node of the entire Trie

public:
    Trie() {                  // Constructor to initialize the Trie
        root = new TrieNode(); // Create the starting empty root node
    }

    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* curr = root;           // Start navigation from the root node
        for (char c : word) {            // Iterate through each character in the input word
            int index = c - 'a';         // Convert character to index 0-25 (e.g., 'a' -> 0)
            if (curr->children[index] == nullptr) { // If the character path doesn't exist...
                curr->children[index] = new TrieNode(); // ...create a new node for that character
            }
            curr = curr->children[index]; // Move the pointer to the next character's node
        }
        curr->isEndOfWord = true;        // After the last character, mark the word as complete
    }

    // Function to search for a full word in the Trie
    bool search(string word) {
        TrieNode* curr = root;           // Start search from the root node
        for (char c : word) {            // Iterate through every character in the word
            int index = c - 'a';         // Calculate the index for the current character
            if (curr->children[index] == nullptr) { // If a character in the path is missing...
                return false;            // ...the word cannot exist in the Trie
            }
            curr = curr->children[index]; // Move deeper into the tree for the next character
        }
        return curr->isEndOfWord;        // Return true only if the final node marks a word's end
    }

    // Function to check if any word starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;           // Start prefix search from the root node
        for (char c : prefix) {          // Iterate through every character in the prefix
            int index = c - 'a';         // Calculate the 0-25 index for the character
            if (curr->children[index] == nullptr) { // If the path breaks at any point...
                return false;            // ...no word with this prefix exists
            }
            curr = curr->children[index]; // Move to the next node in the path
        }
        return true;                     // If we reach the end of the loop, the prefix exists
    }
};

// Main function to test the Trie implementation
int main() {
    Trie* myTrie = new Trie();          // Instantiate a new Trie object on the heap

    cout << "Inserting 'apple'..." << endl;
    myTrie->insert("apple");            // Insert the word "apple"

    cout << "Search 'apple': " << (myTrie->search("apple") ? "Found" : "Not Found") << endl; // Should be true
    cout << "Search 'app': " << (myTrie->search("app") ? "Found" : "Not Found") << endl;     // Should be false
    cout << "StartsWith 'app': " << (myTrie->startsWith("app") ? "Yes" : "No") << endl;      // Should be true

    myTrie->insert("app");              // Now insert "app" as a full word
    cout << "Search 'app' after insert: " << (myTrie->search("app") ? "Found" : "Not Found") << endl; // Should be true

    return 0;                           // End of program
}