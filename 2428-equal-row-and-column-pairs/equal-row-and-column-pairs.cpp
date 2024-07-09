class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        set<vector<int>> st;
        unordered_map<int, vector<int>> dupe;

        for (int i = 0; i < n; i++) {
            if (st.find(grid[i]) != st.end()) {
                dupe[i] = grid[i];
            } else {
                st.insert(grid[i]);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v;

            for(int j = 0; j < n; j++) {
                v.push_back(grid[j][i]);
            }

            if (st.find(v) != st.end()) {
                for (auto row : dupe) {
                    if (row.second == v) {
                        count++;
                    }
                }

                count++;
            }
        }

        return count;
    }
};