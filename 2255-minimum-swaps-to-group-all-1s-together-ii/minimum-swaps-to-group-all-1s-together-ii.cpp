class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int onesCount = 0;

        for (int num : nums) {
            if (num == 1) {
                onesCount++;
            }
        }

        //If there is no ones, then no swap required
        if (onesCount == 0) return 0;

        int maxOnesInWindow = 0, currOnes = 0;
        //Finding the number of ones in the current window
        for (int i = 0; i < onesCount; i++) {
            if (nums[i] == 1) {
                currOnes++;
            }
        }
        maxOnesInWindow = currOnes;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] == 1) {
                currOnes--;
            }
            if (nums[(i + onesCount - 1) % n] == 1) {
                currOnes++;
            }
            maxOnesInWindow = max(maxOnesInWindow, currOnes);
        }

        //Calculating the number of swaps
        return onesCount - maxOnesInWindow;
    }
};