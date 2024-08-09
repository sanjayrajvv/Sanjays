class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for (int i = 0; i < roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];

            degree[a]++;
            degree[b]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push(degree[i]);
        }

        double totalImportance = 0;
        int val = 1;
        while (!pq.empty()) {
            int deg = pq.top(); 
            pq.pop();

            totalImportance += double(val) * deg;
            val++;
        }

        return totalImportance;
    }
};