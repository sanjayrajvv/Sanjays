class Solution {
private:
    string turnWheel(string s, int wheel, int direction) {
        s[wheel] = (s[wheel] - '0' + direction + 10) % 10 + '0';
        return s;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<pair<string, int>> q;

        string start = "0000";
        if (visited.count(start)) return -1;
        
        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == target) return steps;

            for (int i = 0; i < 4; ++i) {
                for (int direction : {-1, 1}) {
                    string next = turnWheel(current, i, direction);
                    if (!visited.count(next)) {
                        q.push({next, steps + 1});
                        visited.insert(next);
                    }
                }
            }
        }

        return -1;
    }
};



