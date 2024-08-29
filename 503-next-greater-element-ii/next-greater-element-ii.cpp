class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);  // Initialize the result vector with -1
        stack<int> monoStack;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!monoStack.empty() && monoStack.top() <= nums[i % n]) {
                monoStack.pop();
            }

            if (!monoStack.empty()) {
                nge[i % n] = monoStack.top();
            }

            monoStack.push(nums[i % n]);
        }

        return nge;
    }
};
