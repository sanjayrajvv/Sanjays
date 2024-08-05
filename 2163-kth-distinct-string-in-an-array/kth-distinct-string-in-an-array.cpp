class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> stringFreq;
        for (string& str : arr) {
            stringFreq[str]++;
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