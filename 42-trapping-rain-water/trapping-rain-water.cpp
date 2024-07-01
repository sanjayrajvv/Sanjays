class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;

        int leftMax = 0, rightMax = 0;

        int water = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < leftMax) {
                    water += (leftMax - height[l]);
                } else {
                    leftMax = height[l];
                }
                l++;
            } else {
                if (height[r] < rightMax) {
                    water += (rightMax - height[r]);
                } else {
                    rightMax = height[r];
                }
                r--;
            }
        }

        return water;
    }
};