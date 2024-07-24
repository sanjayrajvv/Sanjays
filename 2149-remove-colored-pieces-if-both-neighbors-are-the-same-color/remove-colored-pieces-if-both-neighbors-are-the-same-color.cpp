class Solution {
public:
    bool winnerOfGame(string colors) {
        int countAlice = 0;
        int countBob = 0;

        // Count 'A's
        int count = 0;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == 'A') {
                count++;
            } else {
                if (count >= 3) {
                    countAlice += count - 2;
                }
                count = 0;
            }
        }
        if (count >= 3) {
            countAlice += count - 2;
        }

        // Count 'B's
        count = 0;
        for (int i = 0; i < colors.size(); i++) {
            if (colors[i] == 'B') {
                count++;
            } else {
                if (count >= 3) {
                    countBob += count - 2;
                }
                count = 0;
            }
        }
        if (count >= 3) {
            countBob += count - 2;
        }

        cout<<"Alice:"<<countAlice<<"Bob:"<<countBob;

        if (countAlice == 0 || countAlice == countBob) {
            return false;
        }

        return countAlice > countBob;
    }
};
//find how many Alice and Bob can remove
//who can remover greater will win