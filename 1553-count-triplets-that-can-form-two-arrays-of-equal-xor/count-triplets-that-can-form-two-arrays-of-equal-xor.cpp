class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int triplets = 0;
        for (int i = 0; i < arr.size(); i++) {
            int subArray = arr[i];
            for (int j = i + 1; j < arr.size(); j++) {
                subArray ^= arr[j];

                if (subArray == 0) {
                    triplets += (j - i);
                }
            }
        }

        return triplets;
    }
};
//problem boils down to number of subarrays have xor zeros