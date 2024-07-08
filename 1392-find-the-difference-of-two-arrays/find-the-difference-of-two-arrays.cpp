class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        for (int num : nums1) {
            if (set2.find(num) == set2.end()) {
                ans[0].push_back(num);
                set2.insert(num);
            }
        }

        for (int num : nums2) {
            if (set1.find(num) == set1.end()) {
                ans[1].push_back(num);
                set1.insert(num);
            }
        }

        return ans;
    }
};