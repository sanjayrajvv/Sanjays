class Solution {
private:
    int delRow[4] = {0, 1, -1, 0};
    int delCol[4] = {1, 0, 0, -1};

    bool isBound(int r, int c, int n) {
        return r >= 0 && c >= 0 && r < n && c < n;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
 
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, 
        pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        int maxHeight = grid[0][0];
        pq.push({maxHeight, {0, 0}});
        vis[0][0] = 1;

         while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int height = t.first;
            int r = t.second.first;
            int c = t.second.second;

            //maxHeight = max(maxHeight, height);

            if (r == n - 1 && c == n - 1) return height;

            for (int i = 0; i < 4; i++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if (isBound(nr, nc, n) && !vis[nr][nc]) {
                    pq.push({max(grid[nr][nc], height), {nr, nc}});
                    vis[nr][nc] = true;
                }
            }
        }

        return -1;
    }
};