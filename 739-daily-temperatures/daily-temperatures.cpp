class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> answer(n);
        answer[n - 1] = 0;

        stack<int> temperatureStack;
        temperatureStack.push(n - 1);

        for (int i = n - 2; i >= 0; i--) {
            while (!temperatureStack.empty() && 
                  temperatures[i] >= temperatures[temperatureStack.top()]) {
                temperatureStack.pop();
            }
            if (temperatureStack.empty()) {
                answer[i] = 0;
            } else {
                int days = temperatureStack.top() - i;
                answer[i] = days;
            }
            temperatureStack.push(i);
        }

        return answer;
    }
};