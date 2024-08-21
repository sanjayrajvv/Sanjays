class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.size();

        vector<int> mp(26, 0);
        for (char c : s) {
            if (c != '?') mp[c - 'a']++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>, comp> pq;
        
        for (int i = 0; i < 26; i++) {
            pq.push({mp[i], i + 'a'});
        }

        string replacementLetters = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                auto [count, c] = pq.top();
                pq.pop();

                replacementLetters += c;

                pq.push({count + 1, c});
            }
        }

        sort(replacementLetters.begin(), replacementLetters.end());

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = replacementLetters[j];
                j++;
            }
        }

        return s;
    }

private:
    struct comp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first > b.first) return true; 
            else if (a.first == b.first) {
                return a.second > b.second;  
            } else {
                return false;
            }
        }
    };
};
