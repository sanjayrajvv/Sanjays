class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int finalAns = INT_MIN, maxi = 0;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            maxi += nums[i];
        }

        finalAns = maxi;

        int i = 1, j = k;
        while (j < n) {
            maxi = maxi - nums[i - 1];
            maxi = maxi + nums[j];

            finalAns = max(finalAns, maxi);
            i++;
            j++;
        }

        return double(finalAns) / k;

    }
};

/*Maxi = 0;
For (i = 0; i < k; i++) maxi = maxi + A[i];
I = 1, j = k;
Final = INT_MIN;
Final = max(maxi, final);
While (j < n) {
	Maxi = maxi - A[i- 1];
	Maxi = maxi + A[j];
	I++;
	J++;
	Final = max(maxi, final)
}
Return (final / k);
}*/
