class Solution {
private:
    bool makesquareHelper(int index, vector<int> &matchsticks, 
    vector<int>& sides, int target) {
        if (index == matchsticks.size()) {
            return sides[0] == target && 
            sides[1] == target && sides[2] == target && sides[3] == target;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index];
                if (makesquareHelper(index + 1, matchsticks, sides, target)) {
                    return true;
                }
                sides[i] -= matchsticks[index];
            }
            if (sides[i] == 0) break;
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;

        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        int target = sum / 4;

        return makesquareHelper(0, matchsticks, sides, target);
    }
};