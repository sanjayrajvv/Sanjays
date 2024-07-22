class Solution {
private:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n + 1);  // Initialize with size n+1

        for (int i = 0; i < paths.size(); i++) {
            int x = paths[i][0];
            int y = paths[i][1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        return graph;
    }

public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph = createGraph(n, paths);
        vector<int> color(n + 1, 0);  // Initialize with size n+1

        for (int i = 1; i <= n; ++i) {
            vector<bool> used(5, false);  // To check which colors are used by adjacent nodes

            for (int neighbor : graph[i]) {
                if (color[neighbor] != 0) {
                    used[color[neighbor]] = true;
                }
            }

            for (int col = 1; col <= 4; ++col) {
                if (!used[col]) {
                    color[i] = col;
                    break;
                }
            }
        }

        // Exclude the 0th element for 1-based indexing result
        return vector<int>(color.begin() + 1, color.end());
    }
};
