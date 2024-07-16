class Solution {
private:
    void dfs(int index, string digits, unordered_map<char, string> m, 
    string s, vector<string> &ans) {
        if (index == digits.size()) {
            ans.push_back(s);
            return;
        }

        string str = m[digits[index]];
        for (int i = 0; i < str.size(); i++) {
            s.push_back(str[i]);
            dfs(index + 1, digits, m, s, ans);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> ans;
        string s = "";

        dfs(0, digits, m, s, ans);

        return ans;
    }
};