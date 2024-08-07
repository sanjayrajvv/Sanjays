class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int res = nums[0];
        long long total = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            total += nums[i];
            int avg = (total + i) / (i + 1); // Avoid floating-point arithmetic
            res = max(res, avg);
        }

        return res;
    }
};
