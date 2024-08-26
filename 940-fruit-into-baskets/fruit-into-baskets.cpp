class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int, int> fruitCount;
        int maxFruits = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            fruitCount[fruits[r]]++;

            while (fruitCount.size() > 2) {
                fruitCount[fruits[l]]--;

                if (fruitCount[fruits[l]] == 0) {
                    fruitCount.erase(fruits[l]);
                }
                l++;
            }

            maxFruits = max(maxFruits, r - l + 1);
        }

        return maxFruits;
    }
};