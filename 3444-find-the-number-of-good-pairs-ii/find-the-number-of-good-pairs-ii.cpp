typedef long long ll;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> mp;
        for (int el : nums2) {
            mp[el * k]++;
        }

        ll ans = 0;
        for (int n : nums1) {
            if (n % k) continue;

            for (int f = 1; f * f <= n; f++) {
                if (n % f) continue;

                int f1 = f;
                int f2 = n / f;
                ans += mp[f1];
                if (f1 != f2) {
                    ans += mp[f2];
                }
            }
        }

        return ans;
    }
};