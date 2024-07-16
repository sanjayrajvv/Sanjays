class Solution {
private:
    void merge(int l, int mid, int r, vector<int> &A) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        
        vector<int> X(n1);
        vector<int> Y(n2);

        for (int i = 0; i < n1; i++) X[i] = A[l + i];
        for (int j = 0; j < n2; j++) Y[j] = A[mid + 1 + j];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (X[i] <= Y[j]) {
                A[k] = X[i];
                i++;
            } else {
                A[k] = Y[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of X[], if any
        while (i < n1) {
            A[k] = X[i];
            i++;
            k++;
        }

        // Copy remaining elements of Y[], if any
        while (j < n2) {
            A[k] = Y[j];
            j++;
            k++;
        }
    }

    void mergeSort(int l, int r, vector<int> &nums) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;
        mergeSort(l, mid, nums);
        mergeSort(mid + 1, r, nums);

        merge(l, mid, r, nums);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size() - 1, nums);
        return nums;
    }
};
