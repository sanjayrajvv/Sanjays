class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();

        int i = 0;

        vector<string> ans;

        while (i < n) {
            string num = to_string(nums[i]);
            string range = num;

            bool flag = 0;
            while (i + 1 < n && (nums[i] + 1) == nums[i + 1]) {
                flag = 1;
                i++;
            }

            if (flag) range += "->" + to_string(nums[i]);

            ans.push_back(range);

            i++;
        }

        return ans;
    }
};