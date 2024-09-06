class Solution {
private:
    int MOD = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse = findNextSmallerElement(arr);
        vector<int> psee = findPrevSmallerEqualElement(arr);

        int totalCount = 0;
        for (int i = 0; i < n; i++) {
            long  left = i - psee[i];
            long right = nse[i] - i;

            totalCount = (totalCount + left * right * arr[i]) % MOD;
        }

        return totalCount;
    }

private:
    vector<int> findNextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        return nse;
    }

    vector<int> findPrevSmallerEqualElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                psee[i] = st.top();
            }
            st.push(i);
        }

        return psee;
    }
};