class Solution {
    void computeMax(vector<int>& prefixMax, vector<int>& suffixMax, vector<int>& height) {
        prefixMax[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        suffixMax[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefixMax(n), suffixMax(n);

        computeMax(prefixMax, suffixMax, height);

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += max(0, min(prefixMax[i], suffixMax[i]) - height[i]);
        }

        return water;
    }
};