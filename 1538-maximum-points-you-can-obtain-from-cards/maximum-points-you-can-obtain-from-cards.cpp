class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int rightSum = 0;
        int maxSum = leftSum;

        int r = n - 1;
        for (int l = k - 1; l >= 0; l--) {
            leftSum -= cardPoints[l];
            rightSum += cardPoints[r];
            r--;

            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};