class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<string, int> mp;

        for (int i = 0; i < rectangles.size(); i++) {
            int a = rectangles[i][0];
            int b = rectangles[i][1];

            int divisor = gcd(a, b);

            a = a / divisor;
            b = b / divisor;

            string key = to_string(a) + '/' + to_string(b);

            mp[key]++;
        }

        long long interchangeable = 0;
        for (auto i : mp) {
            int n = i.second;

            long long combination = static_cast<long long>(n) * (n - 1) / 2;
            interchangeable += combination;
        }

        return interchangeable;
    }
};