class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int k = 0, n = grades.size();
        
        while ((k + 1) * (k + 2) / 2 <= n) {
            k++;
        }

        return k;
    }
};