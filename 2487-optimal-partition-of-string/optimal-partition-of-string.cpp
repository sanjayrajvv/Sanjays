class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> mp;

        int partition = 0;
        for (char c : s) {
            if (mp[c] == 1) {
                partition++;
                mp.clear();
            }
            mp[c] = 1;
        }

        return partition + 1;
    }
};