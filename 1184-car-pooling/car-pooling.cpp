class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> changes;

        for (const auto& trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            changes[from] += numPassengers;
            changes[to] -= numPassengers;
        }

        int currentPassengers = 0;
        for (auto change : changes) {
            currentPassengers += change.second;
            if (currentPassengers > capacity) {
                return false;
            }
        }

        return true;
    }
};