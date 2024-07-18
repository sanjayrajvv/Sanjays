class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};

        map<string, int> hash;

        string dna = "";
        for (int i = 0; i < 10; i++) {
            dna += s[i];
        }
        hash[dna]++;

        int j = 10;
        while (j < s.size()) {
            dna = dna.substr(1);
            dna += s[j];

            hash[dna]++;
            j++;
        }

        vector<string> sequences;
        for (auto i : hash) {
            if (i.second > 1) {
                sequences.push_back(i.first);
            }
        }

        return sequences;
    }
};