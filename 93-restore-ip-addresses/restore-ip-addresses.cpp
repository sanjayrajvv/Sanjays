class Solution {
private:
    bool isValid(string k) {
        if (k.size() > 3) return false; 
        // No IP segment should have more than 3 digits
        if (k[0] == '0' && k.size() > 1) return false; 
        // No leading zeros allowed unless the segment is "0"

        int num = 0;
        for (char c : k) {
            //if (!isdigit(c)) return false; // Check if the character is a digit
            num = num * 10 + (c - '0'); 
            // Convert char to integer and accumulate the value
            
            if (num > 255) return false; 
            // Immediately return false if it exceeds 255
        }

        return true;
    }

    void restoreHelper(int index, string s, vector<string>& ds, 
    vector<string>& ips) {
        if (index == s.size() && ds.size() == 4) {
            string ip = ds[0];
            for (int i = 1; i < 4; i++) {
                ip += "." + ds[i];
            }
            ips.push_back(ip);
            return;
        }

        if (ds.size() >= 4) return; // No need to proceed if we already have 4 parts

        for (int i = index; i < s.size() && i < index + 3; i++) { 
            // Each part can only be up to 3 digits long
            string part = s.substr(index, i - index + 1);
            if (isValid(part)) {
                ds.push_back(part);
                restoreHelper(i + 1, s, ds, ips);
                ds.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        vector<string> ds;
        restoreHelper(0, s, ds, ips);
        return ips;
    }
};
