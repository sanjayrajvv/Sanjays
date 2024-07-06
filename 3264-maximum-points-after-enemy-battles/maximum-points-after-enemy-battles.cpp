class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int i = 0, j = enemyEnergies.size() - 1;
        
        sort(enemyEnergies.begin(), enemyEnergies.end());
        
        long long points = 0;
        while (i <= j) {
            if (currentEnergy >= enemyEnergies[i]) {
                
                points += (currentEnergy / enemyEnergies[i]);
                
                currentEnergy = currentEnergy % enemyEnergies[i];
            } else if (points > 0) {
                currentEnergy += enemyEnergies[j];
                    j--;
            } else {
                break;
            }
        }
        
        return points;
    }
};