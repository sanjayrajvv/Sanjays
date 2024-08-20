class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int maxEl = 0;
            int largestSum = 0;
            for (int index = i; index < min(n, i + k); index++) {
                maxEl = max(maxEl, arr[index]);
                int sum = maxEl * (index - i + 1) + dp[index + 1];

                largestSum = max(largestSum, sum);
            }  

            dp[i] = largestSum; 
        }

        return dp[0];
    }
};