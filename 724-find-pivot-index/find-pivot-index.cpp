class Solution {
    void calculateSum(vector<int> &prefixSum, vector<int> &suffixSum, vector<int>& nums) {
        int n = prefixSum.size();

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + nums[i + 1];
        }
    }
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixSum(n, 0);
        vector<int> suffixSum(n, 0);

        calculateSum(prefixSum, suffixSum, nums);

        for (int i = 0; i < n; i++) {
            if (prefixSum[i] == suffixSum[i]) {
                return i;
            }
        }

        return -1;
    }
};