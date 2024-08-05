class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> stringFreq;
        for (int i = 0; i < arr.size(); i++) {
            stringFreq[arr[i]]++;
        }

        unordered_set<string> unique;
        for (auto j : stringFreq) {
            if (j.second == 1) {
                unique.insert(j.first);
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (unique.count(arr[i])) {
                k--;
                if (k == 0) {
                    return arr[i];
                }
            }
        }

        return "";
    }
};