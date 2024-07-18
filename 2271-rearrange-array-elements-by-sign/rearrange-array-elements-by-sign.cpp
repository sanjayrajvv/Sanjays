class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive, negative;

        for (int num : nums) {
            if (num > 0) {
                positive.push_back(num);
            } else {
                negative.push_back(num);
            }
        }

        vector<int> result;
        int i = 0, j = 0;
        while (j < negative.size()) {
            result.push_back(positive[i++]);
            result.push_back(negative[j++]);
        }

        return result;
    }
};