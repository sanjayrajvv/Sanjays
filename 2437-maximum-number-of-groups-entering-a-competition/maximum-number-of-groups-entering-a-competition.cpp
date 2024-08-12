class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int l = 0, r = 1000;

        while (l <= r) {
            int k = l + (r - l) / 2;

            if (k * (k + 1) / 2 > n) {
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return r;
    }
};