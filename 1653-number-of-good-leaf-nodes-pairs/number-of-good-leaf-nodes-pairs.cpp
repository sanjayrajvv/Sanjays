/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int countPair(const vector<int> &l, const vector<int> &r, int distance) {
        int count = 0;
        for (int i : l) {
            for (int j : r) {
                if (i + j <= distance) {
                    count++;
                }
            }
        }
        return count;
    }

    vector<int> combine(const vector<int> &l, const vector<int> &r) {
        vector<int> result;
        result.reserve(l.size() + r.size());
        for (int i : l) {
            result.push_back(i + 1);
        }
        for (int i : r) {
            result.push_back(i + 1);
        }
        return result;
    }

    vector<int> dfs(TreeNode* root, int distance, int &count) {
        if (!root) return {};
        if (!root->left && !root->right) {
            return {1};
        }

        vector<int> l = dfs(root->left, distance, count);
        vector<int> r = dfs(root->right, distance, count);

        count += countPair(l, r, distance);

        return combine(l, r);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;

        dfs(root, distance, count);

        return count;
    }
};