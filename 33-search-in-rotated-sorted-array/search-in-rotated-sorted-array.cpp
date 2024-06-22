class Solution {
    //compute mid
    //check is mid is the answer if: yes then return 
    //else: check are in the sorted half,
    //    if so then check that the element is in that range or not : do repeatedly
    //     else check the same in the other half
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) h = mid - 1;
                else l = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[h]) l = mid + 1;
                else h = mid - 1;
            }
        }

        return -1;
    }
};