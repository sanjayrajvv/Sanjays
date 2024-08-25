class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int candidate1, candidate2; // Initialize to different values
        int count1 = 0, count2 = 0;

        // Step 1: Find potential candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            }
        }

        vector<int> result;
        int n = nums.size();
        if (count1 > n / 3) {
            result.push_back(candidate1);
        }
        
        if (count2 > n / 3) {
            result.push_back(candidate2);
        }

        return result;
    }
};
