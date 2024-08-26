class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
            suffix[n - i - 1] = suffix[n - i] + nums[n - i - 1];
        }

        vector<int> result(n);
        result[0] = suffix[1] - (nums[0] * (n - 1));
        result[n - 1] = (nums[n - 1] * (n - 1)) - prefix[n - 2];

        for (int i = 1; i < n - 1; i++) {
            int sumDiff = (nums[i] * i - prefix[i - 1]) + 
                          (suffix[i + 1] - (nums[i] * (n - i - 1)));
            result[i] = sumDiff;
        }

        return result;
    }
};