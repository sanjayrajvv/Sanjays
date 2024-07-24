class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int endTime = intervals[0][1];
        int meetings = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (endTime > intervals[i][0]) continue;

            endTime = intervals[i][1];
            meetings++;
        }

        return intervals.size() - meetings;
    }
};