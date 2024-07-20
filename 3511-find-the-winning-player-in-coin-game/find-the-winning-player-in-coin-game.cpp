class Solution {
private:
    int total = 115;
    int a = 75, b = 10;
public:
    string losingPlayer(int x, int y) {
        bool alice = true;
        while (1) {
            if (alice) {
                int curr_x = 0, curr_y = 0;
                
                bool flag = false;
                for (int i = 0; i <= x; i++) {
                    for (int j = 0; j <= y; j++) {
                        int currTotal = a * i + b * j;
                        if (currTotal == total) {
                            flag = true;
                            curr_x = i;
                            curr_y = j;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                
                if (flag) {
                    x = x - curr_x;
                    y = y - curr_y;
                    
                    alice = false;
                } else {
                    return "Bob";
                }
            } else {
                int curr_x = 0, curr_y = 0;
                
                bool flag = false;
                for (int i = 0; i <= x; i++) {
                    for (int j = 0; j <= y; j++) {
                        int currTotal = a * i + b * j;
                        if (currTotal == total) {
                            flag = true;
                            curr_x = i;
                            curr_y = j;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }
                
                if (flag) {
                    x = x - curr_x;
                    y = y - curr_y;
                    
                    alice = true;
                } else {
                    return "Alice";
                }
            }
        }
        
        return "Alice";
    }
};