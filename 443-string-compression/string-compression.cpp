class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;  // This will keep track of the position to insert characters in the array.
        
        for (int i = 0; i < chars.size();) {
            char current_char = chars[i];
            int count = 0;
            
            // Count the number of occurrences of the current character
            while (i < chars.size() && chars[i] == current_char) {
                i++;
                count++;
            }
            
            // Insert the character
            chars[index++] = current_char;
            
            // If count is greater than 1, insert the number as characters
            if (count > 1) {
                string count_str = to_string(count);
                for (char c : count_str) {
                    chars[index++] = c;
                }
            }
        }
        
        // Resize the vector to the new length
        chars.resize(index);
        
        return index;
    }
};
