class Solution {
    bool canPlace(vector<int>& position, int dis, int m) {
        int count = 1, last = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= dis) {
                count++;
                last = position[i];
            }
        }

        return count >= m ? true : false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int n = position.size();

        int l = 1, h = position[n - 1] - position[0];

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (canPlace(position, mid, m)) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        return h;
    }
};