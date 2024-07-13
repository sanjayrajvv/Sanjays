class Solution {
    void dfs(int room, vector<vector<int>>& rooms, int n, vector<int> &vis) {
        vis[room] = 1;

        for (auto key : rooms[room]) {
            if (!vis[key]) {
                dfs(key, rooms, n, vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> vis(n, 0);

        dfs(0, rooms, n, vis);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) return false;
        }

        return true;
    }
};