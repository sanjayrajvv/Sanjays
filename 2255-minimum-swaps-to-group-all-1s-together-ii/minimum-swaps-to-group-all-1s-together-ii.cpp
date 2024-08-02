class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int onesCount = count(nums.begin(), nums.end(), 1);

        //If there is no ones, then no swap required
        if (onesCount == 0) return 0;

        int maxOnesInWindow = 0;
        //Finding the number of ones in the current window
        int currOnes = count(nums.begin(), nums.begin() + onesCount, 1);
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