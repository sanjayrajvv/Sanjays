class SmallestInfiniteSet {
    int curr;
    set<int> st;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if (!st.empty()) {
            int x = *st.begin();
            st.erase(st.find(x));

            return x;
        } else {
            return curr++;
        }
    }
    
    void addBack(int num) {
        if (num < curr) {
            if (st.find(num) == st.end()) {
                st.insert(num);
            }
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */