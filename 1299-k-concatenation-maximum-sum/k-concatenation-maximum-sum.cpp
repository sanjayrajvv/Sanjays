#define ll long long
class Solution {
private:
    static const int MOD = 1e9 + 7;
    
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // Calculate the maximum subarray sum for a single array
        ll singleMaxSum = maxSubarraySum(arr);

        if (k == 1) {
            return singleMaxSum % MOD;
        }

        // Calculate total sum of the array
        ll totalSum = accumulate(arr.begin(), arr.end(), 0LL);
        totalSum %= MOD;

        // Create a doubled array and calculate its maximum subarray sum
        vector<int> doubleArr(arr);
        doubleArr.insert(doubleArr.end(), arr.begin(), arr.end());
        ll doubleMaxSum = maxSubarraySum(doubleArr);
        
        // If total sum is positive, we need to consider the full contributions from k-2 arrays
        if (totalSum > 0) {
            return (doubleMaxSum + (k - 2) * totalSum % MOD) % MOD;
        } else {
            // If total sum is negative or zero, we only consider the maximum subarray sum of the doubled array
            return doubleMaxSum % MOD;
        }
    }

private:
    ll maxSubarraySum(const vector<int>& arr) {
        ll currSum = 0;
        ll maxSum = 0;
        for (int num : arr) {
            currSum = max(0LL, currSum + num);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
