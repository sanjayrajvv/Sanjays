class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total = 0;
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int count = 0, i = 0, j = n - 1;
        while (count < k) {
            while (pq1.size() < candidates && i <= j) pq1.push(costs[i++]);
            while (pq2.size() < candidates && i <= j) pq2.push(costs[j--]);

            int a = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (a <= b) {
                total += a;
                pq1.pop();
            } else {
                total += b;
                pq2.pop();
            }

            count++;
        }


        return total;
    }
};
