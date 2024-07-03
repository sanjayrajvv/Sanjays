class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //{index, height}
        int n = heights.size();
        stack<pair<int, int>> st;

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                auto top = st.top();
                st.pop();

                int width = i - top.first;
                int height = top.second;

                maxArea = max(maxArea, height * width);
                start = top.first;
            }

            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            auto top = st.top();
            st.pop();

            int width = n - top.first;
            int height = top.second;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};