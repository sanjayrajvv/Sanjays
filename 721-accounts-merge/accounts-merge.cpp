class DisjointSet {
    vector<int> parent, rank;
    public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUparent(int u) {
        if (parent[u] == u) {
            return u;
        } else {
            return parent[u] = findUparent(parent[u]);
        }
    }

    void Union(int u, int v) {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if (ulp_u == ulp_v) return;
        else if (rank[ulp_u] > rank[ulp_v]) parent[ulp_v] = ulp_u;
        else if (rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        //Creating DSU
        DisjointSet ds(n);
        map<string, int> mapMailNode;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.Union(i, mapMailNode[mail]);
                }
            }
        }

        //Merging the mail
        vector<string> mergedMail[n];
        for (auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUparent(it.second);

            mergedMail[node].push_back(mail);
        }

        //Creating final merged list
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            } 

            ans.push_back(temp);
        }

        return ans;
    }
};