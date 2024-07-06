class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        for (int i = 0; i < 2; i++) {
            colors.push_back(colors[i]);
        }
        
        int n = colors.size(), count = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i - 1] != colors[i] && colors[i] != colors[i + 1]) {
                count++;
            }
        }
        
        return count;
    }
};