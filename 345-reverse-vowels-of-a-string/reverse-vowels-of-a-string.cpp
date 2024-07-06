class Solution {
    bool isVowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
        || x == 'u' || x == 'A' || x == 'E' || x == 'I'
        || x == 'O' || x == 'U') return true;
        else return false;
    }
public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            while (l < r && !isVowel(s[l])) {
                l++;
            }

            while (l < r && !isVowel(s[r])) {
                r--;
            }

            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }

        return s;
    }
};