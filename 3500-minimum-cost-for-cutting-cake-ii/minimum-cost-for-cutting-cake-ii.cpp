class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        priority_queue<pair<int, bool>, vector<pair<int, bool>>> pq;
        
        for (int i = 0; i < m - 1; i++) pq.push({horizontalCut[i], true});
        for (int i = 0; i < n - 1; i++) pq.push({verticalCut[i], false});
        
        long long cost = 0;
        int horizontalPieces = 1, verticalPieces = 1;
        
        while (!pq.empty()) {
            auto [cutCost, isHorizontal] = pq.top();
            pq.pop();
            
            if (isHorizontal) {
                cost += cutCost * verticalPieces;
                horizontalPieces++;
            } else {
                cost += cutCost * horizontalPieces;
                verticalPieces++;
            }
        }
        
        return cost;
    }
};