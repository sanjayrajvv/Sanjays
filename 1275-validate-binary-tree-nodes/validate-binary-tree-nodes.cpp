class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, 
                                vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) {
            return false;
        }

        vector<int> vis(n, 0);
        if (!dfs(root, n, leftChild, rightChild, vis)) {
            return false;  // Cycle detected or disconnected components
        }

        // Check if all nodes were visited (no disconnected components)
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) return false;
        }

        return true;
    }

private:
    bool dfs(int node, int n, vector<int>& leftChild, vector<int>& rightChild, 
            vector<int>& vis) {
        vis[node] = 1;

        int children[] = {leftChild[node], rightChild[node]};

        for (int child : children) {
            if (child == -1) continue;
            if (vis[child]) return false;
            if (!dfs(child, n, leftChild, rightChild, vis)) {
                return false;
            }
        }

        return true;
    }

    int findRoot(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_set<int> children;
        children.insert(leftChild.begin(), leftChild.end());
        children.insert(rightChild.begin(), rightChild.end());

        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }

        return -1;
    }
};