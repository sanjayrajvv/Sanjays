class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> fruitsCount;
        int maxFruits = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            fruitsCount[fruits[r]]++;

            while (fruitsCount.size() > 2) {
                fruitsCount[fruits[l]]--;
                if (fruitsCount[fruits[l]] == 0) {
                    fruitsCount.erase(fruits[l]);
                }

                l++;
            }

            if (fruitsCount.size() <= 2) {
                maxFruits = max(maxFruits, r - l + 1);
            }
        }

        return maxFruits;
    }
};