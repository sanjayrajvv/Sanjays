class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long maxScore = 0;
        
        // Get the next greater element indices
        vector<int> nge = nextGreaterElement(nums);

        int i = 0;
        while (i < n - 1) {
            int j = nge[i];  // The index of the next greater element
            if (j == n) break;  // If no next greater element exists
           
            maxScore += (j - i) * (long long)nums[i];
            i = j;  // Move to the next greater element index
        }

        return maxScore;
    }

private:
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, n - 1);  // Initialize with 'n' meaning no next greater element
        stack<int> monoStack;   // Monotonic stack

        // Traverse the array from right to left to find the next greater element
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack that are smaller or equal to nums[i]
            while (!monoStack.empty() && nums[monoStack.top()] <= nums[i]) {
                monoStack.pop();
            }

            if (!monoStack.empty()) {
                nge[i] = monoStack.top();
            }

            // Push the current index onto the stack
            monoStack.push(i);
        }

        return nge;
    }
};
