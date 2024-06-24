class Solution {
    int factorial(int k) {
        int fact = 1;
        for (int i = 1; i <= k; i++) fact = fact * i;

        return fact;
    }
public:
    string getPermutation(int n, int k) {
        int fact = factorial(n - 1);

        vector<int> numbers(n);
        iota(numbers.begin(), numbers.end(), 1);

        string ans = "";
        
        k--;
        while (1) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            if (numbers.size() == 0) break;

            k = k % fact;
            fact = fact / numbers.size();
        }

        return ans;
    }
};