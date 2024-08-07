class Solution {
private:
    int f(int i, unordered_map<int, int>& count, vector<int>& nums, int k) {
        if (i == nums.size()) {
            return 1;
        }

        int beutifulSubsets = f(i + 1, count, nums, k);
        if (count[nums[i] + k] == 0 && count[nums[i] - k] == 0) {
            count[nums[i]]++;
            beutifulSubsets += f(i + 1, count, nums, k);
            count[nums[i]]--;
        }

        return beutifulSubsets;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        return f(0, count, nums, k) - 1; //removing emopty substring
    }
};