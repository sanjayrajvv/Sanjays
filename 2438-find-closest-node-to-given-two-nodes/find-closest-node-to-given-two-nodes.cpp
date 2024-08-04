class Solution {
private:
    void bfs(int startNode, vector<int>& edges, vector<int>& dis) {
        queue<int> q;
        q.push(startNode);
        dis[startNode] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            int neighbor = edges[node];
            if (neighbor != -1 && dis[node] + 1 < dis[neighbor]) {
                dis[neighbor] = dis[node] + 1;
                q.push(neighbor);
            }
        }

    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, INT_MAX);
        vector<int> dis2(n, INT_MAX);

        bfs(node1, edges, dis1);
        bfs(node2, edges, dis2);

        int minDist = INT_MAX;
        int meetingNode = -1;

        for (int i = 0; i < n; i++) {
            if (dis1[i] != INT_MAX && dis2[i] != INT_MAX) {
                int maxDist = max(dis1[i], dis2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    meetingNode = i;
                }
            }
        }

        return meetingNode;
    }
};