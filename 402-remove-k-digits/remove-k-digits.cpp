class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n) return "0";

        stack<char> st;

        // Process each digit in the input number
        for (int i = 0; i < n; i++) {
            // Remove digits from the stack if they are larger than the current digit
            // and we still have some digits to remove (k > 0)
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If there are still digits to remove, pop from the end of the stack
        while (k > 0 && !st.empty()) {  // Added check to prevent stack underflow
            st.pop();
            k--;
        }

        // Build the result string from the stack
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Since we built the answer from the stack, it's in reverse order, so reverse it
        reverse(ans.begin(), ans.end());

        // Remove leading zeros from the result
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        ans = ans.substr(start);

        // If the result is empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};
