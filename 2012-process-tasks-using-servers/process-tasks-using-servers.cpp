class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using Server = pair<int, int>; // {weight, index}
        using Task = pair<int, int>;   // {finish time, index}

        priority_queue<Server, vector<Server>, greater<Server>> freeServers;
        priority_queue<Task, vector<Task>, greater<Task>> processingServers;

        // Initialize free servers with their weight and index.
        for (int i = 0; i < servers.size(); ++i) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans;
        int time = 0;

        for (int i = 0; i < tasks.size(); ++i) {
            time = max(time, i);

            // Release servers that have finished processing.
            while (!processingServers.empty() && processingServers.top().first <= time) {
                freeServers.push({servers[processingServers.top().second], processingServers.top().second});
                processingServers.pop();
            }

            // If no servers are free, fast forward time to when the next server is available.
            if (freeServers.empty()) {
                time = processingServers.top().first;
                while (!processingServers.empty() && processingServers.top().first <= time) {
                    freeServers.push({servers[processingServers.top().second], processingServers.top().second});
                    processingServers.pop();
                }
            }

            // Assign the task to the next available server.
            auto [weight, index] = freeServers.top();
            freeServers.pop();
            ans.push_back(index);
            processingServers.push({time + tasks[i], index});
        }

        return ans;
    }
};
