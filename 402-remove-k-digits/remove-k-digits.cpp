class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char n : num) {
            while (!st.empty() && k > 0 && st.top() > n) {
                st.pop();
                k--;
            }
            st.push(n);
        }

        while (k > 0 && !st.empty()) {  
            st.pop();
            k--;
        }

        string str = "";
        while (!st.empty()) {
            str += st.top();
            st.pop();
        }

        reverse(str.begin(), str.end());

        int start = 0;
        while (start < str.size() && str[start] == '0') {
            start++;
        }

        string ans = str.substr(start);

        return ans.empty() ? "0" : ans;
    }
};