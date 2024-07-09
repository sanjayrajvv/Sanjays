class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long totalTime = 0, completionTime = 0;

        for (int i = 0; i < customers.size(); i++) {
            int arrivalTime = customers[i][0];
            int cookingTime = customers[i][1];

            if (completionTime < arrivalTime) {
                completionTime = arrivalTime + cookingTime;
            } else {
                completionTime += cookingTime;
            } 

            totalTime += (completionTime - arrivalTime);
        }

        return double(totalTime) / customers.size();
    }
};