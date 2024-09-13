class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n + 1);
        for (auto path : paths) {
            int u = path[0];
            int v = path[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n + 1, 0);
        vector<int> answer;

        backtrack(1, n, graph, color, answer);

        return answer;
    }

    bool backtrack(int node, int n, vector<vector<int>>& graph, 
                vector<int>& color, vector<int>& answer) {
        if (node > n) {
            return true;
        }

        for (int col = 1; col <= 4; col++) {
            if (isPossible(node, col, graph, color)) {
                color[node] = col;
                answer.push_back(col);

                if (backtrack(node + 1, n, graph, color, answer) == true) {
                    return true;
                }

                answer.pop_back();
                color[node] = 0;
            }
        }

        return false;
    }

    bool isPossible(int node, int col, vector<vector<int>>& graph, vector<int>& color) {
        for (auto nei : graph[node]) {
            if (color[nei] == col) {
                return false;
            }
        }

        return true;
    }
};