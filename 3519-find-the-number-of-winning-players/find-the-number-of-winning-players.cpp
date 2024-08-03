class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int winners = 0;
        unordered_map<int, map<int, int>> mp;
        for (auto& pair : pick) {
            int player = pair[0];
            int color = pair[1];

            mp[player][color]++;
        }

        for (auto it : mp) {
            int player = it.first;
            auto& colorCounts = it.second;

            for (auto j : colorCounts) {
                if (j.second > it.first) {
                    winners++;
                    break;
                }
            }
        }

        return winners;
    } 
};