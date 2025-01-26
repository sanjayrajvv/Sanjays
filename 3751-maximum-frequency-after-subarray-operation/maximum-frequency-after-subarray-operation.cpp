

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int original_k = count(nums.begin(), nums.end(), k);
        unordered_set<int> unique_v(nums.begin(), nums.end());
        int max_freq = original_k; // Initialize with the original count of k
        
        for (int v : unique_v) {
            int current_sum = 0;
            int max_sub = INT_MIN;
            bool first = true;
            
            for (int num : nums) {
                int t = 0;
                if (num == v) {
                    t += 1;
                }
                if (num == k) {
                    t -= 1;
                }
                
                if (first) {
                    current_sum = t;
                    max_sub = t;
                    first = false;
                } else {
                    current_sum = max(t, current_sum + t);
                    max_sub = max(max_sub, current_sum);
                }
            }
            
            if (max_sub != INT_MIN) {
                max_freq = max(max_freq, original_k + max_sub);
            }
        }
        
        return max_freq;
    }
};