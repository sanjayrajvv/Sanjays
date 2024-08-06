class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for (char c : word) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto& it : freq) {
            maxHeap.push({it.second, it.first});
        }

        unordered_map<char, int> presses;
        int press = 0;
        while (!maxHeap.empty()) {
            char c = maxHeap.top().second;
            maxHeap.pop();
            presses[c] = press / 8 + 1;
            press++;
        }

        int totalPresses = 0;
        for (char c : word) {
            totalPresses += presses[c];
        }

        return totalPresses;
    }
};
