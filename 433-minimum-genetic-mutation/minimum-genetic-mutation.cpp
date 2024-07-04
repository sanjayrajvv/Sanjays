class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        set<string> st(bank.begin(), bank.end());
        st.erase(startGene);

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            string gene = q.front().first;
            int step = q.front().second;
            q.pop();
            
            //check for end word
            if (gene == endGene) {
                return step;
            }
            
            //changing each character of the string and 
            //checking is there exist in the set
            for (int i = 0; i < gene.size(); i++) {
                char original = gene[i];

                for (auto c : genes) {
                    gene[i] = c;
                    if (st.find(gene) != st.end()) {
                        q.push({gene, step + 1});
                        st.erase(gene);
                    }
                }

                gene[i] = original;
            }
        }

        return -1;
    }
};