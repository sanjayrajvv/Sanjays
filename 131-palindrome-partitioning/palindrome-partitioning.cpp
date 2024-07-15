class Solution {
    bool is_palindrome(string k) {
        for (int i = 0; i < k.size() / 2; i++) {
            if (k[i] != k[k.size() - i - 1]) {
                return 0;
            }
        }

        return 1;
    }

    void f(int index, string s, vector<string> &ds, vector<vector<string>> &ans) {
        if (index == s.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (is_palindrome(s.substr(index, i - index + 1))) {
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