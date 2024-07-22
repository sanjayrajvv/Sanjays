class Solution {
private:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(n);
        for (const auto& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }
        return graph;
    }

    bool dfs(int u, int target, vector<vector<int>>& graph, vector<vector<int>>& memo, vector<bool>& visited) {
        if (u == target) {
            return true;
        }
        if (memo[u][target] != -1) {
            return memo[u][target];
        }
        visited[u] = true;
        for (int v : graph[u]) {
            if (!visited[v] && dfs(v, target, graph, memo, visited)) {
                return memo[u][target] = true;
            }
        }
        visited[u] = false;
        return memo[u][target] = false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph = createGraph(numCourses, prerequisites);
        vector<vector<int>> memo(numCourses, vector<int>(numCourses, -1));
        vector<bool> ans;
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            vector<bool> visited(numCourses, false);
            ans.push_back(dfs(u, v, graph, memo, visited));
        }

        return ans;
    }
};
