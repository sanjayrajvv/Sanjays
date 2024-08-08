class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // Define a priority queue with a custom comparator
        priority_queue<vector<int>, vector<vector<int>>, 
                        greater<vector<int>>> pq;
        
        // Add the original indices to the tasks for tracking
        for (int i = 0; i < tasks.size(); ++i) {
            tasks[i].push_back(i);
        }

        // Sort the tasks by their enqueue time
        sort(tasks.begin(), tasks.end());
        
        long long currTime = tasks[0][0];
        pq.push({tasks[0][1], tasks[0][2], tasks[0][1]});
        int i = 1;

        vector<int> schedule;
        while (!pq.empty() || i < tasks.size()) {
            while (i < tasks.size() && currTime >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2], tasks[i][1]});
                i++;
            }

            if (pq.empty()) {
                currTime = tasks[i][0];
                continue;
            }

            int processingTime = pq.top()[0];
            int index = pq.top()[1];
            pq.pop();
            schedule.push_back(index);
            currTime += processingTime;
        }

        return schedule;
    }
};