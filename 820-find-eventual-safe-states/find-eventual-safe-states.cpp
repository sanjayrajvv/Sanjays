class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> rGraph(n);
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int node : graph[i]) {
                rGraph[node].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe(n, 0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe[node] = 1;

            for (int nei : rGraph[node]) {
                inDegree[nei]--;
                if (inDegree[nei] == 0) {
                    q.push(nei);
                }
            } 
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (safe[i] == 1) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

//reverse the graph
//calculate the inDegree
//do topsort, return the visited nodes