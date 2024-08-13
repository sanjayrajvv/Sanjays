class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> anomaly(nums.size(), 0);
        vector<bool> result;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] % 2 == nums[i] % 2) {
                anomaly[i] = 1;
            }
        }

        int prefix = 0;
        for (int i = 0; i < anomaly.size(); i++) {
            prefix += anomaly[i];
            anomaly[i] = prefix;;
        }

        for (auto q : queries) {
            if (anomaly[q[0]] ==  anomaly[q[1]]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};