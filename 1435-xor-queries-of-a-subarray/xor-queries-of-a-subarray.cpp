class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> answer;

        int xorOfarr = 0;
        for (int i = 0; i < n; i++) {
            xorOfarr ^= arr[i];
        }

        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] ^ arr[i + 1];
        }


        for (auto query : queries) {
            int left = query[0];
            int right = query[1];

            int rangeXor = xorOfarr ^ prefix[left] ^ suffix[right];
            answer.push_back(rangeXor);
        }

        return answer;
    }
};