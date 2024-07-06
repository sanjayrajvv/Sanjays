class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int bedSize = flowerbed.size();

        int count = 0;
        for (int i = 0; i < bedSize; i++) {
            bool flag = true;

            if (flowerbed[i] == 1) {
                flag = false;
                continue;
            }

            if (i - 1 >= 0) {
                if (flowerbed[i - 1] != 0) {
                    flag = false;
                }
            }

            if (i + 1 < bedSize) {
                if (flowerbed[i + 1] != 0) {
                    flag = false;
                }
            }

            if (flag) {
                flowerbed[i] = 1;
                count++;
            }
        }

        if (count >= n) return true;
        else return false;
    }
};