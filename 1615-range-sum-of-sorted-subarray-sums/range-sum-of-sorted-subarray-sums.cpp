class Solution {
public:
    int rangeSum(std::vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        // Min-heap to store the sums and their corresponding indices
        std::priority_queue<std::pair<int, int>, 
        std::vector<std::pair<int, int>>, std::greater<>> minHeap;
        
        // Initialize the heap with (element value, index) pairs
        for (int i = 0; i < n; ++i) {
            minHeap.push({nums[i], i});
        }

        int res = 0;
        // Iterate up to 'right' to calculate the sum of ranges
        for (int i = 0; i < right; ++i) {
            auto [num, index] = minHeap.top(); 
            minHeap.pop();
            // Add to the result if within the range [left, right]
            if (i >= left - 1) {
                res = (res + num) % MOD;
            }
            // Push the next pair (sum with the next element, next index) into the heap
            if (index + 1 < n) {
                minHeap.push({num + nums[index + 1], index + 1});
            }
        }
        return res;
    }
};