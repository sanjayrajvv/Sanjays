#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
    int f(int index, vector<int> &v, map<int, int> &mp, vector<int> &dp) {
        if (index < 0) return 0;
        if (index == 0) {
            return mp[v[index]] * v[index];
        }
        
        if (dp[index] != -1) return dp[index];
        
        int pick = mp[v[index]] * v[index];
        if (index > 0 && v[index - 1] != v[index] - 1) {
            pick += f(index - 1, v, mp, dp);
        } else {
            pick += f(index - 2, v, mp, dp);
        }
        
        int notPick = f(index - 1, v, mp, dp);
        
        return dp[index] = max(pick, notPick);
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }

        vector<int> v;
        for (auto i : mp) {
            v.push_back(i.first);
        }

        int n = v.size();
        vector<int> dp(n, -1);
        return f(n - 1, v, mp, dp);
    }
};
