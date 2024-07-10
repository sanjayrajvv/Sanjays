class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        vector<int> ans;

        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            int d = (digits[i] + carry) % 10;
            ans.insert(ans.begin(), d); // Insert at the beginning to avoid reversing later
            carry = (digits[i] + carry) / 10; 
        }

        if (carry == 1) ans.insert(ans.begin(), carry); // Handle the final carry

        return ans;
    }
};
