class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        int j = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (merged[j][1] >= intervals[i][0]) {
                merged[j][1] = max(merged[j][1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
                j++;
            }
        }

        return merged;
    }
};