class Solution {
private:
    void backtrack(int i, string s, vector<bool> &used, 
                    vector<string> &result, string tiles) {
        if (!s.empty()) {
            result.push_back(s);
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            backtrack(i + 1, s + tiles[i], used, result, tiles);
            used[i] = false;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size(), false);
        vector<string> result;
        backtrack(0, "", used, result, tiles);

        return result.size();
    }
};