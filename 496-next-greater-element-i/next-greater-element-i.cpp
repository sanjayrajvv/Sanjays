class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> nge(n2);
        unordered_map<int, int> nums2Index;
        stack<int> monoStack;

        for (int i = n2 - 1; i >= 0; i--) {
            nums2Index[nums2[i]] = i;

            while (!monoStack.empty() && monoStack.top() < nums2[i]) {
                monoStack.pop();
            }
            if (monoStack.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = monoStack.top();
            }
            monoStack.push(nums2[i]);
        }

        vector<int> answer;
        for (int i = 0; i < n1; i++) {
            int index = nums2Index[nums1[i]];

            answer.push_back(nge[index]);
        }

        return answer;
    }
};