class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int, int> count;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
        }

        int numberOfDeletions = 0;
        unordered_set<int> usedFreq;
        for (auto[c, freq] : count) {
            while (freq > 0 && usedFreq.count(freq)) {
                freq--;
                numberOfDeletions++;
            }
            usedFreq.insert(freq);
        }

        return numberOfDeletions;
    }
};