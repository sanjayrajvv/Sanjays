class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

public:
    Node(int key, int value) {
        this->key = key;
        this->val = value;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    unordered_map<int, Node*> nodeAddress;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
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
        if (nodeAddress.find(key) == nodeAddress.end()) {
            return -1;
        }

        Node* node = nodeAddress[key];
        int value = node->val;

        removeNode(node);
        addNode(node);

        return value;
    }
    
    void put(int key, int value) {
        if (nodeAddress.find(key) != nodeAddress.end()) {
            Node* node = nodeAddress[key];
            node->val = value;

            removeNode(node);
            addNode(node);
        } else {
            if (nodeAddress.size() == capacity) {
                Node* lru = tail->prev;

                removeNode(lru);
                nodeAddress.erase(lru->key);
                delete lru;
            }

            Node* newNode = new Node(key, value);
            addNode(newNode);
            nodeAddress[key] = newNode;
        }
    }

private:
    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
};
