class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                string substr = "";
                while (st.top() != '[') {
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop();

                string k = "";
                while (!st.empty() && isdigit(st.top())) {
                    k = st.top() + k;
                    st.pop();
                }

                int n = stoi(k);

                string repeatedString = "";
                for (int j = 0; j < n; j++) {
                    repeatedString += substr;
                }

                for (char ch : repeatedString) {
                    st.push(ch);
                }
            }
        }

        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};