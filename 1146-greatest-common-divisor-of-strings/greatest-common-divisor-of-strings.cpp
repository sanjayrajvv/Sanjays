class Solution {
    int _gcd(int r1, int r2) {
        while (r2 > 0) {
            int temp = r2;
            int remainder = r1 % r2;
            r2 = remainder;
            r1 = temp;
        }

        return r1;
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        return str1.substr(0, _gcd(str1.size(), str2.size()));
    }
};