class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT, window;

        int m = s.size(), n = t.size();
        for (int i = 0; i < n; i++) {
            countT[t[i]]++;
        }

        int length = INT_MAX;
        int startIndex = -1;
        int count = 0, countNeeded = countT.size();

        int l = 0;
        for (int r = 0; r < m; r++) {
            if (countT.find(s[r]) != countT.end()) {
                window[s[r]]++;
                if (window[s[r]] == countT[s[r]]) count++;
            }

            while (count == countNeeded) {
                if ((r - l + 1) < length) {
                    length = r - l + 1;
                    startIndex = l;
                }

                if (countT.find(s[l]) != countT.end()) {
                    window[s[l]]--;

                    if (window[s[l]] < countT[s[l]]) {
                        count--;
                    }
                }
                l++;
            }
        }

        if (startIndex == -1) return "";
        return s.substr(startIndex, length);
    }
};