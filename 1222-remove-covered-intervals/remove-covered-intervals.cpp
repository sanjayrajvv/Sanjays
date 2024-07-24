class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int> &a, const vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; 
        });

        int count = 0;
        int end = 0;
        for (const auto &interval : intervals) {
            if (interval[1] <= end) {
                count++;
            } else {
                end = interval[1];
            }
        }

        return intervals.size() - count;
    }
};