class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, 
                        vector<int>& needs) {
        n = needs.size();
        return findLowestPrice(0, price, special, needs);
    }

private:
    int n;

    int findLowestPrice(int i, vector<int>& price, vector<vector<int>>& special, 
                        vector<int>& needs) {
        if (i == special.size()) {
            int cost = 0;
            for (int index = 0; index < n; index++) {
                cost += price[index] * needs[index];
            }

            return cost;
        }

        //not apply offer
        int notApply = findLowestPrice(i + 1, price, special, needs);

        bool canApply = true;
        for (int index = 0; index < n; index++) {
            needs[index] -= special[i][index];
            if (needs[index] < 0) {
                canApply = false;
            }
        }

        //apply
        int apply = INT_MAX;
        if (canApply) {
            apply = special[i][n] + findLowestPrice(i, price, special, needs);
        }

        //backtrack
        for (int index = 0; index < n; index++) {
            needs[index] += special[i][index];
        }

        return min(apply, notApply);
    }
};