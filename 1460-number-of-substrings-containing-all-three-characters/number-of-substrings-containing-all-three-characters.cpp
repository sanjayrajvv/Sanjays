class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        
        int totalCount = 0;
        int lastSeen[3] = {-1, -1, -1};

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;

            if (i >= 2)
            totalCount += (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
        }
        
        return totalCount;
    }
};