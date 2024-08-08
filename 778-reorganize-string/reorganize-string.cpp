class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxHeap.push({freq[i], i + 'a'});
            }
        }

        string ans = "";
        pair<int, char> prev = {-1, '#'}; // To store the last used character

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            ans += ch;

            if (prev.first > 0) {
                maxHeap.push(prev); 
                // push back the previous character if it still has remaining count
            }

            // Update the previous character
            prev = {count - 1, ch};
        }

        // Check if the reorganized string is valid
        if (ans.length() != s.length()) {
            return "";
        }

        return ans;
    }
};
