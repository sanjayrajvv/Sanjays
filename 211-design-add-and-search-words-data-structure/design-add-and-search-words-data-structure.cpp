struct Node {
    Node* links[26];
    bool flag = false;

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }

    bool searchInNode(string& word, int i, Node* node) {
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
    
    bool search(string word) {
        Node* node = root;
        return searchInNode(word, 0, node);
    }
};