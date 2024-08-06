class Solution {
private:
    string f(int index, string s, unordered_set<string> &uniqueStrings) {
        if (index == s.size()) {
            if (!uniqueStrings.count(s)) {
                return s;
            } else {
                return "";
            }
        }

        s[index] = '1';
        string k = f(index + 1, s, uniqueStrings);
        if (!k.empty()) return k;

        s[index] = '0';
        return f(index + 1, s, uniqueStrings);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> uniqueStrings(nums.begin(), nums.end());
        string s(nums.size(), '0');

        return f(0, s, uniqueStrings);
    }
};