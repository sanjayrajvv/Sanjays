class Solution {
private:
    int MOD = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int>& arr) {

        vector<int> nse = findNSE(arr); //next smaller element index
        vector<int> pse = findPSEE(arr); //previous smaller or equal to element index

        int totalCount = 0;
        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            totalCount = (totalCount + ((long long)left * right * arr[i]) % MOD) % MOD;
        }

        return totalCount;
    }

private:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse(n, n);

        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
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

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();

        vector<int> pse(n, -1);

        stack<int> st;
        for (int i = 0; i < n; i++) {
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