class Solution {
public:
    bool winnerOfGame(string colors) {
        int countAlice = 0;
        int countBob = 0;
        int countA = 0;
        int countB = 0;

        for (char color : colors) {
            if (color == 'A') {
                countA++;
                if (countA >= 3) {
                    countAlice++;
                }
                countB = 0;  // Reset B count
            } else if (color == 'B') {
                countB++;
                if (countB >= 3) {
                    countBob++;
                }
                countA = 0;  // Reset A count
            }
        }

        return countAlice > countBob;
    }
};
