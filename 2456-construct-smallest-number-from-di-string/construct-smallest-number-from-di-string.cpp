class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string result;
        stack<int> stk;

        for (int i = 0; i <= n; i++) {
            // Push the current digit onto the stack
            stk.push(i + 1);

            // If the pattern is 'I' or we are at the last character, pop the stack
            if (i == n || pattern[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result;
    }
};
