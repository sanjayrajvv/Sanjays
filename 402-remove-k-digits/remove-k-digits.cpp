class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n) return "0";

        stack<char> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k--) {
            st.pop();
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }

        ans = ans.substr(start);

        return ans.empty() ? "0" : ans;
    }
};