class Solution {
private:
    bool canPartition(int index, int currentSum, int targetSum, int k, 
                        vector<int>& nums, vector<bool>& visited) {
        if (k == 0) return true; // only one subset left, it must be valid
        if (currentSum == targetSum) {
            // Found a valid subset, now find next subset
            return canPartition(0, 0, targetSum, k - 1, nums, visited);
        }

        for (int i = index; i < nums.size(); i++) {
            if (i > 0 and !visited[i - 1] and nums[i] == nums[i - 1]) {
                continue;
            }

            if (!visited[i] && currentSum + nums[i] <= targetSum) {
                visited[i] = true;
                if (canPartition(i + 1, 
                    currentSum + nums[i], targetSum, k, nums, visited)) {
                    return true;
                }
                visited[i] = false; // backtrack
            }
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;

        int targetSum = sum / k;
        sort(nums.rbegin(), nums.rend()); // Sorting in descending order for optimization

        vector<bool> visited(nums.size(), false);
        return canPartition(0, 0, targetSum, k, nums, visited);
    }
};
