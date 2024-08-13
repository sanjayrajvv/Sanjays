class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int max0 = arr[0]; //0 deletion
        int max1 = arr[0]; //1 deletion
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            int current = arr[i];

            max1 = max(max1 + current, max0);
            max1 = max(max1, current);

            max0 = max(max0 + current, current);

            result = max(result, max1);
        }

        return result;
    }
};