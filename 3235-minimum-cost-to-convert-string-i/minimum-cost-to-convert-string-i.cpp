class Solution {
public:
    long long minimumCost(string source, string target, 
    vector<char>& original, vector<char>& changed, vector<int>& cost) {
        if (source.size() != target.size()) return -1;

        vector<vector<long long>> A(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < 26; i++) A[i][i] = 0;
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            
            A[u][v] = min(A[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (A[i][k] != LLONG_MAX && A[k][j] != LLONG_MAX) {
                        A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                    }
                }
            }
        }

        long long minCost = 0;
        for (int i = 0; i < source.size(); i++) {
            int original = source[i] - 'a';
            int changed = target[i] - 'a';

            if (A[original][changed] == LLONG_MAX) return -1;

            minCost += A[original][changed];
        }

        return minCost;
    }
};