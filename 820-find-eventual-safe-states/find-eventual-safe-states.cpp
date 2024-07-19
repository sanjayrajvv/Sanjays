class Solution {
private:
    bool dfs(int node, int n, vector<vector<int>>& graph, vector<int> &visited,
    vector<int> &pathVisited, vector<int> &check) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto adj : graph[node]) {
            if (!visited[adj]) {
                if (dfs(adj, n, graph, visited, pathVisited, check) == true) {
                    check[adj] = 0;
                    return true;
                }
            } else if (pathVisited[adj]) {
                check[adj] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVisited[node] = 0;

        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0), pathVisited(n, 0), check(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, n, graph, visited, pathVisited, check);
            }
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};