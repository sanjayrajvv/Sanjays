class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minElement = arrays[0][0];
        int maxElement = arrays[0].back();
        int result = 0;

        for (int i = 1; i < arrays.size(); i++) {

            int dis1 = abs(minElement - arrays[i].back());
            int dis2 = abs(maxElement - arrays[i][0]);
            result = max({result, dis1, dis2});

            minElement = min(minElement, arrays[i][0]);
            maxElement = max(maxElement, arrays[i].back());
        }

        return result;
    }
};