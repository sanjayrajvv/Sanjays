class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefix(n);
        
        bitset<50> seenA, seenB;  // Assuming elements in A and B are
        //between 1 and 10000
        
        for (int i = 0; i < n; ++i) {
            seenA[A[i]] = 1;
            seenB[B[i]] = 1;
            
            // Perform bitwise AND and count the number of set 
            //bits (common elements)
            prefix[i] = (seenA & seenB).count();
        }
        
        return prefix;
    }
};
