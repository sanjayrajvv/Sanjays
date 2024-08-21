class Solution {
public:
    int minimumDeletions(string word, int k) {
        
        unordered_map<char, int> m;
        
        for(int i=0; i<word.length(); ++i)
            m[word[i]]+=1;
        
        vector<int> fr;
        
        for(auto i=m.begin(); i!=m.end(); ++i) 
            fr.push_back(i->second);

        
        sort(fr.begin(), fr.end());
        int mx = fr.back();

        int low = 0;
        int high = k;
        
        int res = 1e9;
        bool stat = true;
        
        while(high <= mx) {
            int now = find(low, high, fr);
            res = min(now, res);
            
            ++low;++high;
            stat = false;
        }
        
        if(stat)
            return 0;

        return res;   
    }

private:
    int find(int low, int high, vector<int> &fr) {
        int res = 0;
        
        for(int i = 0; i < fr.size(); ++i) {
            int curr = fr[i];
            
            if(curr < low)
                res+=curr;
            else if(curr > high)
                res+=curr-high;        
        }

        return res;
    }
};
