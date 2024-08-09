class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        priority_queue<int> maxHeap;
        for (auto it : freq) {
            maxHeap.push(it.second);
        }

        int half = n / 2;
        int totalRemovals = 0;
        int minSet = 0;
        while (!maxHeap.empty()) {
            totalRemovals += maxHeap.top();
            maxHeap.pop();
            minSet++;

            if (totalRemovals >= half) {
                return minSet;
            }
        }

        return minSet;
    }
};