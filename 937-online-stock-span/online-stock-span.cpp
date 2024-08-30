class StockSpanner {
private:
    int index;
    stack<pair<int, int>> stocks;
public:
    StockSpanner() {
        index = -1;
        stocks = {};
    }
    
    int next(int price) {
        index++;
        while (!stocks.empty() && price >= stocks.top().first) {
            stocks.pop();
        }

        int span;
        if (stocks.empty()) {
            span = index + 1;
        } else {
            span = index - stocks.top().second;
        }
        stocks.push({price, index});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */