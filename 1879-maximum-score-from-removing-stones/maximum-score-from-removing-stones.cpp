class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);

        int score = 0;
        while (maxHeap.size() > 1) {
            int piles1 = maxHeap.top(); maxHeap.pop();
            int piles2 = maxHeap.top(); maxHeap.pop();

            score++;
            if (piles1 - 1) maxHeap.push(piles1 - 1);
            if (piles2 - 1) maxHeap.push(piles2 - 1);
        }

        return score;
    }
};