struct TrieNode {
    TrieNode *children[26];
    bool endOfWord = false;

    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }

    void put(char ch, TrieNode *node) {
        children[ch - 'a'] = node;
    }

    TrieNode *get(char ch) {
        return children[ch - 'a'];
    }

    void setEnd() {
        endOfWord = true;
    }

    bool isEnd() {
        return endOfWord;
    }
};

class Solution {
private:
    void insertWord(string &product) {
        TrieNode *node = trie;
        for (char c : product) {
            if (!node->containsKey(c)) {
                node->put(c, new TrieNode());
            }
            node =node->get(c);
        }

        node->setEnd();
    }

    vector<string> searchWords(string prefix) {
        vector<string> result;

        TrieNode *node = trie;
        for (char c : prefix) {
            if (!node->containsKey(c)) {
                return {};
            }
            node =node->get(c);
        }

        dfs(node, prefix, result);
        
        return result;
    }

    void dfs(TrieNode *node, string pre, vector<string> &result) {
        if (result.size() == 3) return;
        if (node->isEnd()) result.push_back(pre);

        for (char c = 'a'; c <= 'z'; c++) {
            if (node->containsKey(c)) {
                dfs(node->get(c), pre + c, result);
            }
        }
    }
public:
    TrieNode *trie;

    Solution() {
        trie = new TrieNode();
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, 
    string searchWord) {
        for (string &product : products) {
            insertWord(product);
        }

        vector<vector<string>> result;
        string prefix;
        for (char &c : searchWord) {
            prefix += c;
            result.push_back(searchWords(prefix));
        } 

        return result;
    }
};