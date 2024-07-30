class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        vector<int> maxScores(n);
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; i++) {
            pairs.push_back({ages[i], scores[i]});
        }
        sort(pairs.begin(), pairs.end());

        for (int i = 0; i < n; i++) {
            maxScores[i] = pairs[i].second;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i].second >= pairs[j].second) {
                    maxScores[i] = max(maxScores[i], pairs[i].second + maxScores[j]);
                }
            }
        }

        return *max_element(maxScores.begin(), maxScores.end());
    }
};
