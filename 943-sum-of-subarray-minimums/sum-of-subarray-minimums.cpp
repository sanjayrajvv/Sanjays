class Solution {
private:
    static constexpr int MOD = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNextSmallerElements(arr); // Next smaller element index
        vector<int> pse = findPreviousSmallerOrEqualElements(arr); // Previous smaller or equal to element index

        long long totalCount = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int left = i - pse[i];
            int right = nse[i] - i;
            totalCount = (totalCount + static_cast<long long>(left) * right * arr[i]) % MOD;
        }

        return static_cast<int>(totalCount);
    }

private:
    vector<int> findNextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n); // Default to n (out of bounds)

        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        return nse;
    }

    vector<int> findPreviousSmallerOrEqualElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1); // Default to -1 (out of bounds)

        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        return pse;
    }
};
