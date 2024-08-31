class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int maxPoints = sum;

        int j = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            sum -= cardPoints[i];
            sum += cardPoints[j--];

            maxPoints = max(maxPoints, sum);
        }

        return maxPoints;
    }
};