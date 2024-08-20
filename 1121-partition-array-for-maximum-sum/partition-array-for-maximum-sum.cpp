class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n, -1);

        return f(0, n, arr, k, dp);
    }

private:
    int f(int i, int n, vector<int>& arr, int k, vector<int>& dp) {
        if (i == arr.size()) return 0;

        if (dp[i] != -1) return dp[i];

        int maxEl = 0;
        int largestSum = 0;
        for (int index = i; index < min(n, i + k); index++) {
            maxEl = max(maxEl, arr[index]);
            int sum = maxEl * (index - i + 1) + f(index + 1, n, arr, k, dp);

            largestSum = max(largestSum, sum);
        }  

        return dp[i] = largestSum;      
    }
};