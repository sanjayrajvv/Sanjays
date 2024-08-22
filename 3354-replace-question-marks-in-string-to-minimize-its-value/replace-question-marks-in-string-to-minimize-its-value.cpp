class Solution {
public:
    // Function to minimize the string value by replacing '?' characters
    string minimizeStringValue(string s) {
        int n = s.size();
        string ans = ""; // Initialize the resulting minimized string
        int A[26] = {0}; // Array to store the count of each lowercase English letter
        
        // Step 1: Count the occurrences of each lowercase English letter
        for (auto i : s) {
            if (i != '?') {
                A[i - 'a']++; // Increment the count for non-'?' characters
            }
        }
        
        string dum = ""; // String to store selected letters for '?' characters
        
        // Step 2: Iterate through the string 's' to handle '?' characters
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                int min = 0, cnt = n + 1;
                // Find the lowercase English letter with the minimum count in 'A'
                for (int i = 0; i < 26; i++) {
                    if (A[i] < cnt) {
                        cnt = A[i]; // Update the minimum count
                        min = i;    // Update the index of the minimum count letter
                    }
                }
                A[min]++; // Increment the count of the selected letter
                dum += (char)('a' + min); // Add the selected letter to 'dum'
            }
        }
        
        int j = 0;
        // Step 3: Sort the string 'dum' to ensure letters are in ascending order
        sort(dum.begin(), dum.end());
        
        // Step 4: Iterate through 's' again to replace '?' characters with selected letters
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = dum[j]; // Replace '?' with the corresponding letter from 'dum'
                j++; // Move to the next letter in 'dum'
            }
            ans += s[i]; // Add the character to the resulting string 'ans'
        }
        
        return ans; // Return the minimized string
    }
};