class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> combined;

        stringstream ss1(s1);
        stringstream ss2(s2);

        string str;
        
        while (getline(ss1, str, ' ')) {
            combined[str]++;
        }

        while (getline(ss2, str, ' ')) {
            combined[str]++;
        }

        vector<string> ans;
        for (auto it : combined) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};