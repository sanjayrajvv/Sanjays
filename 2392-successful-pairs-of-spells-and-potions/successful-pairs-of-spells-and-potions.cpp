class Solution {
    int findSuccess(long long spell, vector<int> &potions, long long success) {
        int n = potions.size();
        int l = 0, h = n - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (potions[mid] * spell >= success) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return n - l;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, 
    long long success) {
        int n = spells.size(), m = potions.size();
        vector<int> ans;

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            int count = findSuccess(spells[i], potions, success);
            ans.push_back(count);
        }

        return ans;
    }
};
