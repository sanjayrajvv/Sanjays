#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // Helper function to check if there is a subarray of length 'len' with sum >= target
    bool canFindSubArrayOfLength(int len, int target, const vector<int>& nums) {
        int sum = 0;
        // Calculate the sum of the first 'len' elements
        for (int i = 0; i < len; ++i) {
            sum += nums[i];
        }
        if (sum >= target) return true;

        // Use a sliding window to check the remaining subarrays
        for (int i = len; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - len];
            if (sum >= target) return true;
        }
        
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 1, right = nums.size();
        int minLength = INT_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFindSubArrayOfLength(mid, target, nums)) {
                minLength = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};
