class Solution {
private:
    vector<vector<int>> createGraph(int n, vector<vector<int>>& richer) {
        vector<vector<int>> graph(n);

        for (int i = 0; i < richer.size(); i++) {
            int a = richer[i][0];
            int b = richer[i][1];

            graph[b].push_back(a);
        }

        return graph;
    }

    void dfs(int node, vector<vector<int>> &graph, vector<int>& quiet, 
    vector<int> &answer, vector<int> &vis) {
        vis[node] = 1;
        answer[node] = node;

        for (auto j : graph[node]) {
            if (!vis[j]) {
                dfs(j, graph, quiet, answer, vis);
            }

            if (quiet[answer[j]] < quiet[answer[node]]) {
                answer[node] = answer[j];
            }
        }
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> graph = createGraph(n, richer);

        vector<int> answer(n);
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, quiet, answer, vis);
            }
        }

        return answer;
    }
};

//for every node:
//    do dfs and find quitest