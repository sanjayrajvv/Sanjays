class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int, vector<int>> maxHeap;
        queue<pair<int, int>> q;
        int hash[26] = {0};

        for (int i = 0; i < tasks.size(); i++) {
            hash[tasks[i] - 'A']++;
        }

        for (auto i : hash) {
            if (i > 0) {
                maxHeap.push(i);
            }
        }

        int intervals = 0;
        while (!maxHeap.empty() || !q.empty()) {
            intervals++;

            if (!maxHeap.empty()) {
                if (maxHeap.top() - 1) {
                    q.push({maxHeap.top() - 1, intervals + n});
                }
                maxHeap.pop();
            }

            if (!q.empty() && q.front().second == intervals) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return intervals;
    }
};