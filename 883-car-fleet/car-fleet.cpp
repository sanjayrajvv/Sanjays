class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> ps;

        int n = position.size();
        for (int i = 0; i < n; i++) {
            ps.push_back({position[i], speed[i]});
        }

        sort(ps.begin(), ps.end());

        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {
            double time = (double)(target - ps[i].first) / ps[i].second;
            while (st.empty() || st.top() < time) {
                st.push(time);
            }
        }

        return st.size();
    }
};