class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> stringFreq;
        for (int i = 0; i < arr.size(); i++) {
            stringFreq[arr[i]]++;
        }

        for (string& str : arr) {
            if (stringFreq[str] == 1) {
                k--;
            }
            if (k == 0) {
                return str;
            }
        }

        return "";
    }
};