#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(Node* newnode) {
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new Node(key, value));
        m[key] = head->next;
    }
};

// --- Main Function for Testing in VS Code ---
int main() {
    // Create an LRU Cache with capacity 2
    cout << "Initializing LRUCache with capacity 2..." << endl;
    LRUCache* lRUCache = new LRUCache(2);

    cout << "put(1, 1)" << endl;
    lRUCache->put(1, 1); // cache is {1=1}

    cout << "put(2, 2)" << endl;
    lRUCache->put(2, 2); // cache is {1=1, 2=2}

    cout << "get(1) -> Output: " << lRUCache->get(1) << " (Expected: 1)" << endl;
    // cache is {2=2, 1=1} (1 is now most recently used)

    cout << "put(3, 3)" << endl;
    lRUCache->put(3, 3); 
    // LRU key was 2, evicts key 2, cache is {1=1, 3=3}

    cout << "get(2) -> Output: " << lRUCache->get(2) << " (Expected: -1)" << endl;
    // (returns -1 because 2 was evicted)

    cout << "put(4, 4)" << endl;
    lRUCache->put(4, 4); 
    // LRU key was 1, evicts key 1, cache is {3=3, 4=4}

    cout << "get(1) -> Output: " << lRUCache->get(1) << " (Expected: -1)" << endl;
    // (returns -1 because 1 was evicted)

    cout << "get(3) -> Output: " << lRUCache->get(3) << " (Expected: 3)" << endl;
    cout << "get(4) -> Output: " << lRUCache->get(4) << " (Expected: 4)" << endl;

    return 0;
}