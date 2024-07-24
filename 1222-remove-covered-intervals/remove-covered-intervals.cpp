class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int count = 0;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (end < intervals[i][0]) {
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                if (start <= intervals[i][0] && end >= intervals[i][1]) {
                    count++;
                } else if (start >= intervals[i][0] && end <= intervals[i][1]) {
                    count++;
                    start = intervals[i][0];
                    end = intervals[i][1];
                } else {
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }
        }

        return intervals.size() - count;
    }
};