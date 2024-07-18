class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

        map<string, int> hash;
        vector<string> sequences;

        for (int i = 0; i <= s.size() - 10; i++) {
            string dna = s.substr(i, 10);
            hash[dna]++;

            if (hash[dna] == 2) {
                sequences.push_back(dna);
            }
        }

        return sequences;
    }
};