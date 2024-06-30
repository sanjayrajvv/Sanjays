struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};
class WordDictionary {
    Node *root;
private:
    bool searchInNode(string word, int i, Node *node) {
        if (node == NULL) return false;

        if (i == word.size()) return node->isEnd();

        if (word[i] != '.') {
            return searchInNode(word, i + 1, node->links[word[i] - 'a']);
        }

        for (int j = 0; j < 26; j++) {
            if (searchInNode(word, i + 1, node->links[j])) {
                return true;
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
        
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }
    
    bool search(string word) {
        return searchInNode(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */