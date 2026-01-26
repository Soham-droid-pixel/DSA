#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        // 1. Grouping logic
        for(string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // "eat" becomes "aet"
            mp[key].push_back(s);         // Add "eat" to the "aet" group
        }
        
        // 2. Formatting the output
        vector<vector<string>> result;
        for(auto pair : mp) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    
    vector<vector<string>> result = sol.groupAnagrams(input);
    
    // Printing result
    cout << "[ ";
    for(auto group : result) {
        cout << "[";
        for(string s : group) cout << s << " ";
        cout << "] ";
    }
    cout << "]" << endl;
    
    return 0;
}