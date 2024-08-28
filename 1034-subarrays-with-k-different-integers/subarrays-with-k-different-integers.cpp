class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int lessThanOrEqualTokDifferentIntegers = countSubarrays(nums, k);
        int lessThankDifferentIntegers = countSubarrays(nums, k - 1);

        return lessThanOrEqualTokDifferentIntegers - lessThankDifferentIntegers;
    }

private:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        int totalCount = 0;
        unordered_map<int, int> mp;

        int l = 0;
        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;

            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                
                l++;
            }

            if (mp.size() <= k) {
                totalCount += (r - l + 1);
            }
        }

        return totalCount;
    }
};