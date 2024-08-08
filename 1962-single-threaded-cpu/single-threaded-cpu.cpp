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

        long long currTime = 0;
        int i = 0;
        vector<int> schedule;

        while (i < tasks.size() || !pq.empty()) {
            // Add all tasks that are available by currTime
            while (i < tasks.size() && currTime >= tasks[i][0]) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // If the priority queue is empty and there are still tasks left,
            // jump the current time to the next task's enqueue time
            if (pq.empty()) {
                currTime = tasks[i][0];
                continue;
            }

            // Process the task with the smallest processing time (and smallest index in case of a tie)
            int processingTime = pq.top()[0];
            int index = pq.top()[1];
            pq.pop();
            schedule.push_back(index);
            currTime += processingTime;
        }

        return schedule;
    }
};
