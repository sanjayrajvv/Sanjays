class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> baskets;
        int maxFruits = 0;

        int l = 0;
        for (int r = 0; r < fruits.size(); r++) {
            baskets[fruits[r]]++;

            while (baskets.size() > 2) {
                baskets[fruits[l]]--;
                if (baskets[fruits[l]] == 0) {
                    baskets.erase(fruits[l]);
                }
                l++;
            }

            if (baskets.size() <= 2) {
                maxFruits = max(maxFruits, r - l + 1);
            }
        }

        return maxFruits;
    }
};