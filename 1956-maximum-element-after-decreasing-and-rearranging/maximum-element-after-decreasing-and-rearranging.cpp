class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        int maxElement = arr[0];

        for (auto num : arr) {
            //next number maybe same or one number greater
            maxElement = min(maxElement + 1, num);
        }
        
        return maxElement;
    }
};