class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k <= 0) {
            return ans;
        }
        
        auto cmp = [&nums1, &nums2](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        
        // Initialize the heap with the first element of nums1 paired with all elements of nums2
        for (int i = 0; i < min(static_cast<int>(nums2.size()), k); ++i) {
            minHeap.push({0, i});
        }
        
        while (k-- > 0 && !minHeap.empty()) {
            auto idx_pair = minHeap.top();
            minHeap.pop();
            ans.push_back({nums1[idx_pair.first], nums2[idx_pair.second]});
            if (idx_pair.first + 1 < nums1.size()) {
                minHeap.push({idx_pair.first + 1, idx_pair.second});
            }
        }
        
        return ans;
    }
};
