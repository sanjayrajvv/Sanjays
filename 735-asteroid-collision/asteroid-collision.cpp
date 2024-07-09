class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool collision = false;
            while (!st.empty() && st.top() > 0 && a < 0) {
                if (abs(st.top()) < abs(a)) {
                    st.pop();  // The asteroid on the stack is smaller and is destroyed
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();  // Both asteroids are of equal size and destroy each other
                    collision = true;
                    break;
                } else {
                    collision = true;
                    break;  // The asteroid on the stack is larger and survives
                }
            }
            if (!collision) {
                st.push(a);  // No collision, or the current asteroid survives
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());  // Reverse to get the correct order

        return ans;
    }
};
