class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //step 1 - Find subarray minimums
        vector<int> nse = findNextSmallerElements(nums);
        vector<int> pse = findPreviousSmallerOrEqualElements(nums);

        long long totalSubarrayMinimum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            totalSubarrayMinimum += (long long)left * right * nums[i];
        }

        //step2 - Find subarray maximums
        vector<int> gse = findNextGreaterElements(nums);
        vector<int> pge = findPreviousGreaterOrEqualElements(nums);

        long long totalSubarrayMaximum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int left = i - pge[i];
            int right = gse[i] - i;

            totalSubarrayMaximum += (long long)left * right * nums[i];
        }

        //step 3 - take the difference
        long long ans = totalSubarrayMaximum - totalSubarrayMinimum;
        return ans;
    }

private:
    vector<int> findNextSmallerElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        return nse;
    }

    vector<int> findPreviousSmallerOrEqualElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        return pse;
    }

    vector<int> findNextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> nge(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }

        return nge;
    }

    vector<int> findPreviousGreaterOrEqualElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> pge(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }

        return pge;
    }
};