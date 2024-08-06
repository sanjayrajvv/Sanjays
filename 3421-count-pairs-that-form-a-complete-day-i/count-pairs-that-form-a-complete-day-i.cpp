class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> seenMap;
        long long completeDays = 0;

        for (int hour : hours) {
            int rem = hour % 24;
            int complement = (24 - rem) % 24;
            if (seenMap.find(complement) != seenMap.end()) {
                completeDays += seenMap[complement];
            }
            seenMap[rem]++;
        }

        return completeDays;
    }
};

//Idea : to have a complete player you the two numbers n1, n2 should be
// (n1 % 24 + n2 % 24) % 24 == 0