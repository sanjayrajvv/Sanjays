class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> answer;

        unordered_map<char, string> numberToCharMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        dfs(0, "", digits, numberToCharMap, answer);

        return answer;
    }

private:
    void dfs(int index, string s, string digits, 
        unordered_map<char, string>& numberToCharMap, vector<string>& answer) {
        if (index == digits.size()) {
            answer.push_back(s);
            return;
        }

        string str = numberToCharMap[digits[index]];
        for (char ch : str) {
            dfs(index + 1, s + ch, digits, numberToCharMap, answer);
        }
    }
};