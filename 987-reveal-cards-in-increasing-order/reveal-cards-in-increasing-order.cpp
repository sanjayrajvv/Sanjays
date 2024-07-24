class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());

        deque<int> dq;
        for (int i = 0; i < n; i++) {
            dq.push_back(i);
        }

        vector<int> order(n);
        for (auto j : deck) {
            int i = dq.front(); dq.pop_front();
            order[i] = j;

            if (!dq.empty()) 
                dq.push_back(dq.front()); 
                dq.pop_front();
        }

        return order;
    }
};