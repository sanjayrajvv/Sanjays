class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0, r = n - k;

        // Initial sum of the last k elements
        int sum = accumulate(cardPoints.end() - k, cardPoints.end(), 0);
        int maxPoints = sum;

        // Sliding window to calculate the sum by 
        //removing from the right end and adding to the left end
        while (r < n) {
            sum += cardPoints[l] - cardPoints[r];
            maxPoints = max(maxPoints, sum);
            l++;
            r++;
        }

        return maxPoints;
    }
};
