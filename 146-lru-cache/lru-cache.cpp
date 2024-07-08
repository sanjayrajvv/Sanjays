class Node {
public:
    int key, val;
    Node *prev, *next;

    Node(int key, int val) {
        this->key = key;
        this->val = val;

        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
    Node *head;
    Node *tail;
    
    map<int, Node*> m;
    int n;
public:
    LRUCache(int capacity) {
        n = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node *curr = head;
        while (curr) {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node *node = m[key];
        int value = node->val;

        removeNode(node);
        addNode(node);

        return value;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node *node = m[key];
            node->val = value;

            removeNode(node);
            addNode(node);
        } else {
            if (m.size() == n) {
                Node *lru = tail->prev;
                removeNode(lru);
                m.erase(lru->key);
                delete lru;
            }

            Node *new_node = new Node(key, value);
            addNode(new_node);
            m[key] = new_node;
        }
    }

private:
    void addNode(Node *node) {
        Node *temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }

    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */