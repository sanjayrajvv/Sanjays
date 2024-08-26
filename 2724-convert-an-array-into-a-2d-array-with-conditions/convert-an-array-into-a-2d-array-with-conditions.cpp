class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> count;
        int rows = 0;
        for (int num : nums) {
            count[num]++; 
            rows = max(rows, count[num]);
        }

        vector<vector<int>> result(rows);
        int rowNumber = 0;
        while (!count.empty()) {
            vector<int> toErase;
            for (auto& j : count) {
                result[rowNumber].push_back(j.first);
                j.second--;

                if (j.second == 0) {
                    toErase.push_back(j.first);
                }
            }

            for (int num : toErase) {
                count.erase(num);
            }

            rowNumber++;
        }

        return result;
    }
};