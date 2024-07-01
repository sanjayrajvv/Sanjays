class Solution {
    string createKey(string s) {
        vector<int> count(26, 0);

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        string key = "";
        for (int i = 0; i < count.size(); i++) {
            key += to_string(count[i]) + '#';
        }

        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++) {
            string key = createKey(strs[i]);
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto it : m) {
            ans.push_back(it.second);
        }

        return ans;
    }
};