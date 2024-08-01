class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (int i = 0; i < details.size(); i++) {
            char firstDigit = details[i][11];
            char secondDigit = details[i][12];
            int digit = (firstDigit - '0') * 10 + (secondDigit - '0');

            if (digit > 60) {
                count++;
            }
        }

        return count;
    }
};