class Solution {
    int gcd(int a, int b) {
        if (b > a) {
            gcd(b, a);
        }
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = gcd(nums[0], nums[n - 1]);

        return ans;
    }
};
