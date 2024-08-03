struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    bool isEnd() {
        return flag;
    }

    void setEnd() {
        flag = true;
    }
};

class WordDictionary {
private:
    Node *root;

    bool searchInNode(string word, int i, Node *node) {
        if (node == nullptr) {
            return false;
        }
        if (i == word.size()) {
            return node->isEnd();
        }

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
        Node *node = root;
        return searchInNode(word, 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */