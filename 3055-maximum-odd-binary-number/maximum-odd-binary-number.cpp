class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        string number(n, '0');
        number[n - 1] = '1';

        int count = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;
            }
        }


        for (int i = 0; i < count; i++) {
            number[i] = '1';
        }

        return number;
    }
};