//Use bfs traverse
//While traversing carry the min along the way
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), columns = heights[0].size();

        vector<vector<int>> dis(rows, vector<int>(columns, INT_MAX));
        
        //{dis,{r,c}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        dis[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int dist = pq.top().first;
            pq.pop();

            if (r == rows - 1 && c == columns - 1) {
                return dist;
            }

            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i ++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < columns) {
                    int effort = max(abs(heights[r][c] - heights[nr][nc]), dist);
                    if (effort < dis[nr][nc]) {
                        dis[nr][nc] = effort;
                        pq.push({effort, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};