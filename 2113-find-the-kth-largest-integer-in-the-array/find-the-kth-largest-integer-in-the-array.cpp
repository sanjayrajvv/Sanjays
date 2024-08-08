class Solution {
private:
    struct comp {
        bool operator()(const string &a, const string &b) {
            if (a.size() == b.size()) {
                return a > b;  
            }
            return a.size() > b.size(); 
        }
    };
    
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, comp> minHeap;
        
        for (const string &num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
};
