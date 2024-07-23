class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize) {
            return false;
        }

        unordered_map<int, int> mp;
        for (int i = 0; i < hand.size(); i++) {
            mp[hand[i]]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto j : mp) {
            pq.push(j.first);
        }

        while (!pq.empty()) {
            int minVal = pq.top();
            for (int i = 0; i < groupSize; i++) {
                if (mp[minVal + i] == 0) {
                    return false;
                }

                mp[minVal + i]--;
                if (mp[minVal + i] == 0) {
                    pq.pop();
                }
            }
        }

        return true;
    }
};