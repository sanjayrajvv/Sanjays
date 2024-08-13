class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int max1 = arr[0];  // Max subarray sum with at most one deletion
        int max0 = arr[0];  // Max subarray sum with no deletion
        int result = arr[0];  // Overall maximum sum

        for (int i = 1; i < n; i++) {
            int current = arr[i];
            
            // Update max1: Either include the current element, or start a new subarray with it, 
            // or pick max0 (no deletion up to previous element)
            max1 = max(max1 + current, max0);
            max1 = max(max1, current);

            // Update max0: Either include the current element or start a new subarray with it
            max0 = max(max0 + current, current);

            // Update overall maximum sum
            result = max(result, max1);
        }

        return result;
    }
};
