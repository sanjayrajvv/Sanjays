class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n == 0) return 0;

        int lastFruit = -1;       // Last fruit type in the sequence
        int secondLastFruit = -1;  // Second last fruit type
        int lastFruitCount = 0;    // Count of the last fruit type in the current window
        int currentMax = 0;        // Max number of fruits in the current window
        int maxFruits = 0;         // Overall maximum number of fruits

        for (int i = 0; i < n; i++) {
            if (fruits[i] == lastFruit || fruits[i] == secondLastFruit) {
                // If current fruit is one of the two types we're collecting
                currentMax++;
            } else {
                // New fruit type encountered
                currentMax = lastFruitCount + 1;  // Reset to count of last fruit + current fruit
            }

            // Update last fruit count
            if (fruits[i] == lastFruit) {
                lastFruitCount++;
            } else {
                lastFruitCount = 1;  // New last fruit
            }

            // Update last and second last fruit types
            if (fruits[i] != lastFruit) {
                secondLastFruit = lastFruit;
                lastFruit = fruits[i];
            }

            // Update the global maximum
            maxFruits = max(maxFruits, currentMax);
        }

        return maxFruits;
    }
};
