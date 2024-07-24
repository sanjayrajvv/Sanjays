class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int j = 1; j < intervals.size(); j++) {
            if (end >= intervals[j][0]) {
                end = max(end, intervals[j][1]);
            } else {
                merged.push_back({start, end});
                start = intervals[j][0];
                end = intervals[j][1];
            }
        }
        merged.push_back({start, end});

        return merged;
    }
};