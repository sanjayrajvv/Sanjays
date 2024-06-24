class Solution {
    bool isPal(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }

        return true;
    }
    void f(int index, string s, vector<string> &ds, vector<vector<string>> &ans) {
        if (index == s.size()) {
            ans.push_back(ds);

            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPal(s.substr(index, i - index + 1))) {
                ds.push_back(s.substr(index, i - index + 1));
                f(i + 1, s, ds, ans);
                ds.pop_back();
            } 
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        f(0, s, ds, ans);

        return ans;
    }
};