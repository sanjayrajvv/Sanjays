class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int left = 0, right = (n + 1) / 2;
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                result[i] = nums[left++];
            } else {
                result[i] = nums[right++];
            }
        }

        return result;
    }
};