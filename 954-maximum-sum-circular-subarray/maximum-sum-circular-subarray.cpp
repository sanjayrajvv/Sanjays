class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSub = INT_MIN, currMaxSum = 0;
        int minSub = INT_MAX, currMinSum = 0;
        int total = 0;

        for (int num : nums) {
            currMaxSum += num;
            maxSub = max(maxSub, currMaxSum);
            if (currMaxSum < 0) currMaxSum = 0;

            currMinSum += num;
            minSub = min(minSub, currMinSum);
            if (currMinSum > 0) currMinSum = 0;

            total += num;
        }

        // If all numbers are negative, 
        //maxSub would be the largest single element.
        if (maxSub < 0) return maxSub;

        return max(maxSub, total - minSub);
    }
};
