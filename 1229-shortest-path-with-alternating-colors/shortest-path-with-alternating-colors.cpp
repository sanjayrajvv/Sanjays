class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, 
    vector<vector<int>>& redEdges,   vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n);
        vector<vector<int>> blueGraph(n);

        for (int i = 0; i < redEdges.size(); i++) {
            int u = redEdges[i][0];
            int v = redEdges[i][1];

            redGraph[u].push_back(v);
        }
        for (int i = 0; i < blueEdges.size(); i++) {
            int u = blueEdges[i][0];
            int v = blueEdges[i][1];

            blueGraph[u].push_back(v);
        }

        vector<int> redDis(n, INT_MAX);
        vector<int> blueDis(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({0, 1});
        redDis[0] = 0;
        q.push({0, 2}); //{node, prev edges color} //1-red, 2-blue
        blueDis[0] = 0;

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();

            if (color == 1) {  // Last edge was red, so try to go with blue
                for (auto neighbor : blueGraph[node]) {
                    if (redDis[node] != INT_MAX && 
                    (redDis[node] + 1) < blueDis[neighbor]) {
                        blueDis[neighbor] = (redDis[node] + 1);
                        q.push({neighbor, 2});
                    }
                }
            } else {
                for (auto neighbor : redGraph[node]) {
                    if (blueDis[node] != INT_MAX && 
                    (blueDis[node] + 1) < redDis[neighbor]) {
                        redDis[neighbor] = (blueDis[node] + 1);
                        q.push({neighbor, 1});
                    }
                }
            }
        }

        vector<int> answer(n);
        for (int i = 0; i < n; ++i) {
            int minDis = min(redDis[i], blueDis[i]);
            answer[i] = (minDis == INT_MAX) ? -1 : minDis;
        }

        return answer;
    }
};