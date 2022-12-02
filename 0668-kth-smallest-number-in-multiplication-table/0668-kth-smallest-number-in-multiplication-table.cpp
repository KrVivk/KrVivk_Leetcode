class Solution {
public:
     bool enough(int x, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(x / i, n);
        }
        return (count >= k);
    }

     int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n;
        while (low < high) {
            int mid = (high + low) / 2;
            if (!enough(mid, m, n, k))
                low = mid + 1;
            else 
                high = mid;
        }
        return low;
    }
};
