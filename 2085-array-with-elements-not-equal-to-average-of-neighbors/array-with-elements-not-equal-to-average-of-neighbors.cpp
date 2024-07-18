class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Rearrange in place
        for (int i = 1; i < n - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
        
        return nums;
    }
};
