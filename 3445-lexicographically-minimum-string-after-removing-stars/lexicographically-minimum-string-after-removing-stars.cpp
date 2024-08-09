class Solution {
private:
    struct comp {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };
    
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        unordered_set<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                if (!pq.empty()) {
                    int index = pq.top().second;
                    st.insert(index);
                    pq.pop();
                }
                st.insert(i);
            }
        }

        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (!st.count(i)) {
                ans += s[i];
            }
        }

        return ans;
    }
};