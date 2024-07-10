class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();

        queue<int> rq, dq;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                rq.push(i);
            } else {
                dq.push(i);
            }
        }

        while (!rq.empty() && !dq.empty()) {
            int rFront = rq.front(); rq.pop();
            int dFront = dq.front(); dq.pop();

            if (rFront < dFront) {
                rq.push(rFront + n);
            } else {
                dq.push(dFront + n);
            }
        }

        if (dq.empty()) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};