class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        }

        int l = 0, h = m[key].size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (m[key][mid].first < timestamp) {
                l = mid + 1;
            } else if (m[key][mid].first > timestamp) {
                h = mid - 1;
            } else {
                return m[key][mid].second;
            }
        }


        if (h >= 0) {
            return m[key][h].second;
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */