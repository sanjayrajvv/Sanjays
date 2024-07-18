class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;

        // Loop until the pointers meet or cross
        while (i < j) {
            // If the characters at the current pointers are not equal, break the loop
            if (s[i] != s[j]) break;

            // Move inward past all characters equal to s[i] from the left
            char current_char = s[i];
            while (i <= j && s[i] == current_char) {
                i++;
            }

            // Move inward past all characters equal to s[j] from the right
            while (i <= j && s[j] == current_char) {
                j--;
            }
        }

        // Return the length of the remaining substring
        return j - i + 1;
    }
};
