class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < n; i++) {
            minHeap.push(nums[i]);
        }

        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top());
            minHeap.pop();
        }

        return ans;
    }
};