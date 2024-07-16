class Solution {
private:
    map<string, int> encodeMap;
    map<int, string> decodeMap;
    int count;
public:
    Solution() {
        count = 0;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        encodeMap[longUrl] = ++count;
        decodeMap[count] = longUrl;

        return to_string(count); 
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return decodeMap[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));