class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums1.size(); i++) {
            arr.push_back({nums2[i], nums1[i]});
        }
        sort(arr.rbegin(), arr.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, max_score = 0;

        for (int i = 0; i < arr.size(); i++) {
            int nums1_val= arr[i].second;
            int nums2_val = arr[i].first;

            pq.push(nums1_val);
            sum += nums1_val;

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                max_score = max(max_score, sum * nums2_val);
            }
        }

        return max_score;

    }
};