class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        
        // Add all characters of s to sum
        for (char c : s) {
            sum -= int(c);
        }
        
        // Subtract all characters of t from sum
        for (char c : t) {
            sum += int(c);
        }
        
        // Convert the resulting sum to char, which is the extra character
        char missing = char(sum);
        return missing;
    }
};
