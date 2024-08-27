class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = generateKey(s);

            mp[key].push_back(s);
        }

        vector<vector<string>> groupedAnagrams;
        for (auto j : mp) {
            groupedAnagrams.push_back(j.second);
        }

        return groupedAnagrams;
    }

private:
    string generateKey(string s) {
        vector<int> count(26, 0);

        for (char c : s) {
            count[c - 'a']++;
        }

        string key = "";
        for (int i = 0; i < 26; i++) {
            key += to_string(count[i]) + '#';
        }

        return key;
    }
};