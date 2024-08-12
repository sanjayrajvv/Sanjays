class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor;
        unordered_set<int> distinctColors;
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            if (ballColor.find(ball) != ballColor.end()) {
                int oldColor = ballColor[ball];
                ballColor[ball] = color;
                bool inUse = false;

                for (auto pair : ballColor) {
                    if (pair.second == oldColor) {
                        inUse = true;
                        break;
                    }
                }
                if (!inUse) {
                    distinctColors.erase(oldColor);
                }
            } else {
                ballColor[ball] = color;
            }

            distinctColors.insert(color);
            result.push_back(distinctColors.size());
        }

        return result;
    }
};