class Solution {
private:
    priority_queue<int> maxHeap;
    queue<pair<int, int>> q;

public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskCounts;
        for (char t : tasks) {
            taskCounts[t]++;
        }

        for (auto [task, count] : taskCounts) {
            maxHeap.push(count);
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