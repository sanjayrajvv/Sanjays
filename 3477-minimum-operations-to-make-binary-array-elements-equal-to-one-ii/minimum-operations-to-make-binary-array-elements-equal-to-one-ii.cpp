class Solution {
public:
    int minOperations(vector<int>& nums) {
        bool turn = true;
        int operations = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (turn == true && nums[i] == 0 || turn == false && nums[i] == 1) {
                    operations++;
                    turn = !turn;
            } 
        }

        return operations;
    }
};