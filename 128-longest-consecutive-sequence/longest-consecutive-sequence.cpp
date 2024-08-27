class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        int longest = 0;
        for (int i : st) {
            if (st.find(i - 1) == st.end()) {
                int currentLength = 1;
                int x = i;

                while (st.find(x + 1) != st.end()) {
                    currentLength++;
                    x++;
                }
                longest = max(longest, currentLength);
            }
        }

        return longest;
    }
};