class Solution {
private:
    vector<vector<int>> createGraph(int numCourses, 
    vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[v].push_back(u);
        }

        return graph;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph = createGraph(numCourses, prerequisites);
        vector<int> inDegree(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (auto adj : graph[i]) {
                inDegree[adj]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);

            for (auto i : graph[node]) {
                inDegree[i]--;

                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        if (ans.size() == numCourses) {
            return ans;
        }

        return {};
        
    }
};