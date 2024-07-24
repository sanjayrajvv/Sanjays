class Solution {
private:
    int translateNumber(int num, vector<int> &mapping) {
        int translated = 0;
        int factor = 1;
        if (num == 0) {
            return mapping[0];
        }
        while (num > 0) {
            int digit = num % 10;
            translated = translated + mapping[digit] * factor;
            factor = factor * 10;
            num = num / 10; 
        }
        return translated;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Use a capturing lambda to handle the translation and comparison
        std::sort(nums.begin(), nums.end(), [this, &mapping](int a, int b) {
            return this->translateNumber(a, mapping) < this->translateNumber(b, mapping);
        });
        return nums;
    }
};