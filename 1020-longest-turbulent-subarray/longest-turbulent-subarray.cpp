class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int maxTurb = 1;
        string prev = "";

        int l = 0, r = 1;
        while (r < n) {
            if (arr[r - 1] > arr[r] and prev != ">") {
                maxTurb = max(maxTurb, r - l + 1);
                r++;
                prev =  ">";
            } else if (arr[r - 1] < arr[r] and prev != "<") {
                maxTurb = max(maxTurb, r - l + 1);
                r++;
                prev =  "<";
            } else {
                arr[r] == arr[r - 1] ? r = r + 1 : r;
                l = r - 1;
                prev = "";
            }
        }

        return maxTurb;
    }
};