class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        //{index, height}
        stack<pair<int, int>> histograms;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;
            while (!histograms.empty() && heights[i] < histograms.top().second) {
                auto topHist = histograms.top();
                histograms.pop();

                int width = i - topHist.first;
                int height = topHist.second;

                maxArea = max(maxArea, height * width);
                start = topHist.first;
            }
            histograms.push({start, heights[i]});
        }

        while (!histograms.empty()) {
            auto topHist = histograms.top();
            histograms.pop();

            int width = n - topHist.first;
            int height = topHist.second;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};