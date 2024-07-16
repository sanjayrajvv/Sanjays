#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode *children[26] = {nullptr};
    bool endOfWord = false;
};

class Solution {
public:
    // Insert a word into the trie
    void insertWord(TrieNode *trie, const string &word) {
        for (const char &c : word) {
            int index = c - 'a';
            if (!trie->children[index]) {
                trie->children[index] = new TrieNode;
            }
            trie = trie->children[index];
        }
        trie->endOfWord = true;
    }

    // Search for a prefix in the trie and collect words starting with that prefix
    vector<string> searchWords(TrieNode *trie, const string &prefix) {
        vector<string> result;
        for (const char &c : prefix) {
            int index = c - 'a';
            if (!trie->children[index]) {
                return {};
            }
            trie = trie->children[index];
        }
        dfs(trie, prefix, result);
        return result;
    }

    // Perform DFS to find all words in the trie starting from the given prefix
    void dfs(TrieNode *trie, const string &prefix, vector<string> &result) {
        if (result.size() == 3) {
            return;
        }
        if (trie->endOfWord) {
            result.push_back(prefix);
        }
        for (int i = 0; i < 26; ++i) {
            if (trie->children[i]) {
                dfs(trie->children[i], prefix + (char)(i + 'a'), result);
            }
        }
    }

    // Function to return product suggestions based on the search word
    vector<vector<string>> suggestedProducts(vector<string>& products, const string &searchWord) {
        // Sort the products to ensure the suggestions are lexicographically sorted
        sort(products.begin(), products.end());

        // Initialize the trie
        TrieNode *trie = new TrieNode;
        for (const string &product : products) {
            insertWord(trie, product);
        }

        // Collect suggestions for each prefix of the search word
        vector<vector<string>> result;
        string prefix;
        for (const char &c : searchWord) {
            prefix += c;
            result.push_back(searchWords(trie, prefix));
        }

        return result;
    }
};

