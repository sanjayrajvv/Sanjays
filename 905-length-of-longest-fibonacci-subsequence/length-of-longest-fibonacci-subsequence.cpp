class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int f1 = arr[i];
                int f2 = arr[j];
                int count = 2;
                while (st.find(f1 + f2) != st.end()) {
                    int f3 = f1 + f2;
                    f1 = f2;
                    f2 = f3;

                    ans = max(ans, ++count);
                }
            }
        }

        return ans >= 3 ? ans : 0;

    }
};