class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        vector<pair<int, char>> sortedFreq;
        for (auto it : freq) {
            sortedFreq.push_back({it.second, it.first});
        }
        sort(sortedFreq.rbegin(), sortedFreq.rend()); // Sort in descending order of frequency

        unordered_map<char, int> presses;
        int press = 1;
        for (auto it : sortedFreq) {
            char c = it.second;
            if (press <= 8) {
                presses[c] = 1;
            } else if (press <= 16) {
                presses[c] = 2;
            } else if (press <= 24) {
                presses[c] = 3;
            } else {
                presses[c] = 4;
            }
            press++;
        }

        int totalPresses = 0;
        for (char c : word) {
            totalPresses += presses[c];
        }

        return totalPresses;
    }
};
