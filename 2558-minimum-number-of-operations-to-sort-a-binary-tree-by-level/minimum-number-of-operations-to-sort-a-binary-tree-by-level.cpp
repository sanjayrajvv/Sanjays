class Solution {
public:
    int minimumOperations(TreeNode* root) {
        // Queue for BFS traversal
        queue<TreeNode*> q;
        q.push(root);

        int numberOfSwaps = 0;

        // Level order traversal of the tree
        while (!q.empty()) {
            int size = q.size();
            vector<int> arr;
            
            // Traverse the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                arr.push_back(node->val);

                // Add left and right children to the queue if they exist
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            // Use cycle decomposition to count minimum swaps for sorting
            numberOfSwaps += countMinSwaps(arr);
        }

        return numberOfSwaps;
    }

private:
    // Function to count minimum swaps using cycle decomposition
    int countMinSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> vec(n);
        
        // Store the elements and their indices
        for (int i = 0; i < n; i++) {
            vec[i] = {arr[i], i};
        }

        // Sort the array by element values
        sort(vec.begin(), vec.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        // Find cycles in the permutation
        for (int i = 0; i < n; i++) {
            // If already visited or in correct place, skip
            if (visited[i] || vec[i].second == i) {
                continue;
            }

            // Find the length of the cycle
            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = vec[j].second;
                cycleSize++;
            }

            // If there is a cycle of size 'k', it requires 'k-1' swaps
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
