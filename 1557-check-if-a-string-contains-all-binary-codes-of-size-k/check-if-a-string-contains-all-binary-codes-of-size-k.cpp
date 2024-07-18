class Solution {
public:
    bool hasAllCodes(std::string s, int k) {
        int totalCodes = 1 << k; // 2^k
        if (s.size() < k) return false;

        std::unordered_set<std::string> codes;

        for (int i = 0; i <= s.size() - k; ++i) {
            codes.insert(s.substr(i, k));
        }

        return codes.size() == totalCodes;
    }
};