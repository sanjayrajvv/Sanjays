class LockingTree {
private:
    unordered_map<int, int> mp; // Stores locked nodes and their users
    vector<int> parent; // Stores parent information of each node
    vector<vector<int>> children; // Stores children of each node

public:
    LockingTree(vector<int>& parent) : parent(parent), children(parent.size()) {
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }
    }
    
    bool lock(int num, int user) {
        if (mp.find(num) == mp.end()) {
            mp[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if (mp.find(num) != mp.end() && mp[num] == user) {
            mp.erase(num);
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if (mp.find(num) != mp.end() || !checkDescendant(num) || !checkAncestors(num)) {
            return false;
        }
        mp[num] = user;
        unlockDescendants(num);
        return true;
    }

private:
    bool checkDescendant(int num) {
        for (int child : children[num]) {
            if (mp.find(child) != mp.end() || checkDescendant(child)) {
                return true;
            }
        }
        return false;
    }

    void unlockDescendants(int num) {
        for (int child : children[num]) {
            mp.erase(child);
            unlockDescendants(child);
        }
    }

    bool checkAncestors(int num) {
        int curr = parent[num];
        while (curr != -1) {
            if (mp.find(curr) != mp.end()) {
                return false;
            }
            curr = parent[curr];
        }
        return true;
    }
};
