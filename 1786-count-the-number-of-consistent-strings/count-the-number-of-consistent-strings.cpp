class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int count = 0;

        for (string word : words) {
            bool legal = true;
            for (char ch : word) {
                if (allowedSet.find(ch) == allowedSet.end()) {
                    legal = false;
                    break;
                }
            }
            if (legal) {
                count += 1;
            }
        }

        return count;
    }
};