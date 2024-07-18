class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int i = 0, j = tokens.size() - 1;
        int score = 0;
        sort(tokens.begin(), tokens.end());

        while (i <= j) {
            if (tokens[i] <= power) {
                score++;
                power -= tokens[i];
                i++;
            } else {
                if (score == 0 || i == j) break;

                score--;
                power += tokens[j];
                j--;
            }
        }

        return score;
    }
};
