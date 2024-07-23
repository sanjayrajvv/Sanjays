class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mp(26, 0);
        for (int i = 0; i < s.size(); i++) {
            mp[s[i] - 'a'] = i;
        }

        vector<int> sizes;
        int size = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            size++;

            end = max(end, mp[s[i] - 'a']);
            if (i == end) {
                sizes.push_back(size);
                size = 0;
            }
        }

        return sizes;
    }
};