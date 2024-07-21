class Solution {
private:
    int countVowels(string s) {
        int vowels = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowels++;
            }
        }

        return vowels;
    }
public:
    bool doesAliceWin(string s) {
        int vowels = countVowels(s);

        if (vowels > 0 && vowels % 2 == 0 || vowels % 2) {
            //ALice wins
            return true;
        }

        //Bob wins
        return false;
    }
};