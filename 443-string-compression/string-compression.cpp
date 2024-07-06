class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int n = chars.size();

        int i = 0;
        while(i < n) {
            int count = 0;
            char currChar = chars[i];
            while (i < n && currChar == chars[i]) {
                i++;
                count++;
            }

            chars[index++] = currChar;

            if (count > 1) {
                string num = to_string(count);
                for (char c : num) {
                    chars[index++] = c;
                }
            }
        }

        chars.resize(index);

        return index;
    }
};