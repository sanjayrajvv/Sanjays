class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        
        // Sort intervals based on their end points
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;  // At least one arrow is needed
        int end = points[0][1];  // The end point of the first balloon
        
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > end) {  // No overlap with the previous interval
                arrows++;
                end = points[i][1];  // Update the end point to the current balloon's end point
            }
        }
        
        return arrows;
    }
};
