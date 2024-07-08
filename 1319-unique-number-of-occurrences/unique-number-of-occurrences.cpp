class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        set<int> st;

        for (auto i : m) {
            if (st.find(i.second) != st.end()) return false;
            st.insert(i.second);
        }

        return true;
    }
};