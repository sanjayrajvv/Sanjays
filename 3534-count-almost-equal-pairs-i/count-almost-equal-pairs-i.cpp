class Solution {
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int pairs = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (almostEqual(nums[i], nums[j])) {
                    pairs++;
                }
            }
        }

        return pairs;
    }

private:
    bool almostEqual(int num1, int num2) {
        string strNum1 = to_string(num1);
        string strNum2 = to_string(num2);

        int n = strNum1.size(), m = strNum2.size();
        int maxLen = max(n, m);
        while(n != maxLen){
            strNum1 = "0" + strNum1; 
            n++;
        }
        while(m != maxLen){
            strNum2 = "0" + strNum2; 
            m++;
        }

        int diff = 0;
        unordered_map<char,int> mp1, mp2;
        for(int i = 0; i < maxLen; i++){
            diff += (strNum1[i] != strNum2[i]);
            mp1[strNum1[i]]++; mp2[strNum2[i]]++;
        }

        return diff <= 2 && mp1 == mp2;
    }

};