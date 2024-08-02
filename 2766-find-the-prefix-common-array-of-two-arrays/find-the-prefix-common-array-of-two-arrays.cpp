class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        set<int> setA, setB;

        vector<int> prefix(n);

        for (int i = 0; i < n; i++) {
            setA.insert(A[i]);
            setB.insert(B[i]);

            int count = 0;
            for (int val : setA) {
                if (setB.find(val) != setB.end()) {
                    count++;
                }
            }

            prefix[i] = count;
        }

        return prefix;
    }
};