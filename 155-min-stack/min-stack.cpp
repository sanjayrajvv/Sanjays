class MinStack {
private:
    stack<pair<int, int>> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStack.empty()) {
            minStack.push({val, val});
        } else {
            int currMin = minStack.top().second;

            minStack.push({val, min(currMin, val)});
        }
    }
    
    void pop() {
        minStack.pop();
    }
    
    int top() {
        return minStack.top().first;
    }
    
    int getMin() {
        return minStack.top().second;
    }
};