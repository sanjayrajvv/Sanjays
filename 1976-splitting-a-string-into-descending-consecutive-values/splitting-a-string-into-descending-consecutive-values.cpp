class Solution {
private:
    bool dfs(int index, double prev, const string& s) {
        if (index == s.size()) {
            return true;
        }

        for (int j = index; j < s.size(); j++) {
            double val = stod(s.substr(index, j - index + 1));
            if (val + 1 == prev && dfs(j + 1, val, s)) {
                return true;
            }
        }

        return false;
    }

public:
    bool splitString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            double val = stod(s.substr(0, i + 1));
            if (dfs(i + 1, val, s)) {
                return true;
            }
        }
        return false;
    }
};
