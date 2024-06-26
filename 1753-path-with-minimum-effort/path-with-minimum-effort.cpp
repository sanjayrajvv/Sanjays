class Solution {
public:
    bool canReachEnd(vector<vector<int>>& heights, int mid) {
        int rows = heights.size(), columns = heights[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if (r == rows - 1 && c == columns - 1) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < columns && !visited[nr][nc]) {
                    if (abs(heights[r][c] - heights[nr][nc]) <= mid) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int left = 0, right = 1e6;
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReachEnd(heights, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
