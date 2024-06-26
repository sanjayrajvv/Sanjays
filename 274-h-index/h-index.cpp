class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int maxH = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= maxH) {
                break;
            }

            maxH--;
        }

        return maxH;
    }
};