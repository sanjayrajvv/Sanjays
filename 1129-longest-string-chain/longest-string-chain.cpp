class Solution {
private:
    bool isPredecessor(string &a, string &b) {
        if (a.size() + 1 != b.size()) return false;

        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;
        while (j < n2) {
            if (i < n1 && a[i] == b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }

        if (i == n1 && j == n2) return true;
        else return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        int len = 1;
        vector<int> dp(n, 1);
        for (int index = 1; index < n; index++) {
            for (int prevIndex = 0; prevIndex < index; prevIndex++) {
                if (isPredecessor(words[prevIndex], words[index]) && 
                (1 + dp[prevIndex] > dp[index])) {
                    dp[index] = 1 + dp[prevIndex];
                }
            }
            len = max(len, dp[index]);
        }

        return len;
    }
};