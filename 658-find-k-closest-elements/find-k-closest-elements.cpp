class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //{diff with x, arr[i]}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            pq.push({diff, arr[i]});
        }

        vector<int> result;
        while (k--) {
            int val = pq.top().second;
            pq.pop();
            
            result.push_back(val);
        }

        sort(result.begin(), result.end());

        return result;
    }
};