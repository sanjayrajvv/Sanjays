class Solution {
public:
    int numTrees(int n) {
        vector<int> numTree(n + 1, 1);

        for (int node = 2; node <= n; node++) {
            int total = 0;
            for (int root = 1; root <= node; root++) {
                int left = root - 1;
                int right = node - root;

                total += numTree[left] * numTree[right];
            }
            numTree[node] = total;
        }

        return numTree[n];
    }
};