class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[i] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[i]);

            if (i >= k && dq.front() == nums[i - k]) {
                dq.pop_front();
            }

            if (i >= k - 1) {
                ans.push_back(dq.front());
            }
        }

        return ans;

    }
};