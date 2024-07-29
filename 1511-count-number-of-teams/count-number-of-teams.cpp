class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;

        for (int mid = 0; mid < n; mid++) {
            int leftSmaller = 0;
            int rightLarger = 0;

            for (int left = mid - 1; left >= 0; left--) {
                if (rating[left] < rating[mid]) {
                    leftSmaller++;
                }
            }

            for (int right = mid + 1; right < n; right++) {
                if (rating[right] > rating[mid]) {
                    rightLarger++;
                }
            }

            teams += (leftSmaller * rightLarger);

            int leftLarger = mid - leftSmaller;
            int rightSmaller = n - mid - 1 - rightLarger;

            teams += (leftLarger * rightSmaller);

        }
        
        return teams;
    }
};