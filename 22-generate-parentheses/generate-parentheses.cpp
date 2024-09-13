class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;

        backtrack(1, 0, "(", n, answer);

        return answer;
    }

private:
    void backtrack(int open, int close, string ds, int n, vector<string>& answer) {
        if (open == n && close == n) {
            answer.push_back(ds);
            return;
        }

        if (open < n) backtrack(open + 1, close, ds + "(", n, answer);
        if (open > close) backtrack(open, close + 1, ds + ")", n, answer);
    }
};