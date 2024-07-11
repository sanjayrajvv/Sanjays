class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ')') {
                st.push(s[i]);
            } else {
                string k = "";
                while (st.top() != '(') {
                    k += st.top();
                    st.pop();
                }
                st.pop();

                for (int j = 0; j < k.size(); j++) {
                    st.push(k[j]);
                }
            }
        }

        string reversed = "";
        while (!st.empty()) {
            reversed = reversed + st.top();
            st.pop();
        }

        reverse(reversed.begin(), reversed.end());

        return reversed;
    }
};