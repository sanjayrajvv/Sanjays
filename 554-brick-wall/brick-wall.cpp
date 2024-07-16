class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        //{pos, number of gaps}
        map<int, int> mp;
        for (int i = 0; i < wall.size(); i++) {
            int prev = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                mp[prev + wall[i][j]]++;
                prev = prev + wall[i][j];
            }
        }

        int mini = 0;
        for (auto i : mp) {
            mini = max(mini, i.second);
        }

        return wall.size() - mini;
    }
};