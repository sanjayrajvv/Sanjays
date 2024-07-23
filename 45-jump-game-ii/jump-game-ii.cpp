class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int currentJumpEnd = 0, farthest = 0;
        int jumps = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            // If we have reached the end of the current jump,
            // increase the jump count and update the end for the next jump
            if (i == currentJumpEnd) {
                ++jumps;
                currentJumpEnd = farthest;

                // If the farthest point we can reach is the end of the array, break early
                if (currentJumpEnd >= nums.size() - 1) break;
            }
        }

        return jumps;
    }
};
