class Solution {
private:
    static const bool comp(pair<int, int> &a, pair<int, int> &b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } 
        return a.first > b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<pair<int, int>> freq(mp.begin(), mp.end());

        // sort with increasing frequency, if tied then sort in 
        //decreasing order of their values
        sort(freq.begin(), freq.end(), comp);

        vector<int> ans;
        for (auto j : freq) {
            for (int i = 0; i < j.second; i++) {
                ans.push_back(j.first);
            }
        }

        return ans;
    }
};