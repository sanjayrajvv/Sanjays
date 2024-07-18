class Solution {
private:
    bool bfs(int i, vector<int> &color, vector<vector<int>>& graph) {
        queue<pair<int, int>> q;
        q.push({i, 0});
        color[i] = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto j : graph[node]) {
                if (color[j] == -1) {
                    color[j] = !col;
                    q.push({j, !col});
                } else {
                    if (color[j] == col) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bfs(i, color, graph) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};