class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        vis[0] = 1;
        int farthest = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) {
                return true;
            }

            int minimum = i + minJump;
            int maximum = min(n, i + maxJump + 1); 

            for (int j = max(minimum, farthest + 1); j < maximum; j++) {
                if (j <= farthest) continue;
                if (s[j] == '0' && !vis[j]) {
                    q.push(j);
                    vis[j] = true;
                }
            }
            farthest = maximum - 1;
        }

        return false;
    }
};