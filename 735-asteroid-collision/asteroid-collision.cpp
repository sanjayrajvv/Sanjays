class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool collision = false;
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();
                } else if (abs(st.top()) == abs(a)){
                    st.pop();
                    collision = true;
                    break;
                } else {
                    collision = true;
                    break;
                }
            }
            if (!collision) {
                st.push(a);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};