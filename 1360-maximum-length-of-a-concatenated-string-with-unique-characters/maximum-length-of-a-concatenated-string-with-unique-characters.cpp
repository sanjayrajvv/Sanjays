class Solution {
private:
    int f(int index, vector<int>& mp, vector<string>& arr) {
        if (index == arr.size()) {
            return 0;
        }

        // Check if the current string has unique characters
        vector<int> curr(26, 0);
        bool isUnique = true;
        for (char c : arr[index]) {
            if (curr[c - 'a'] == 1) {
                isUnique = false;
                break;
            }
            curr[c - 'a'] = 1;
        }

        int take = 0;
        if (isUnique) {
            bool canTake = true;
            for (char c : arr[index]) {
                if (mp[c - 'a'] == 1) {
                    canTake = false;
                    break;
                }
            }
            
            if (canTake) {
                // Mark the characters from the current string
                for (char c : arr[index]) {
                    mp[c - 'a'] = 1;
                }
                take = arr[index].size() + f(index + 1, mp, arr);
                // Unmark the characters (backtracking)
                for (char c : arr[index]) {
                    mp[c - 'a'] = 0;
                }
            }
        }

        int notTake = f(index + 1, mp, arr);

        return max(take, notTake);
    }

public:
    int maxLength(vector<string>& arr) {
        vector<int> mp(26, 0);
        return f(0, mp, arr);
    }
};
